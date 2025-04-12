#include <iostream>
#include <ctime>
using namespace std;

struct Vehicle {
    string Id;
    double Fuel_level;
    time_t Last_updated;
};

struct Region {
    string regName;
    Vehicle* vehicle;
    int numVeh;
};

struct FleetManager {
    Region* region;
    int numReg;
};

// Function Prototypes
void input_data(FleetManager*);
void sort_vehicles(FleetManager*);
void add_region(FleetManager*);
void add_vehicle(FleetManager*);
void lowest_fuellevel(FleetManager*);
void remove_inactiveVeh(FleetManager*);
void display(FleetManager*);
void add_vehicle_to_region(Region&, int);

int main() {
    FleetManager fleet = {nullptr, 0};
    int option;
    input_data(&fleet);

    do {
        cout<<"\nSelect an option:\n"
            <<"1. Add New Region\n"
            <<"2. Add Vehicles\n"
            <<"3. Show Vehicle with Lowest Fuel Level\n"
            <<"4. Remove Inactive Vehicles\n"
            <<"5. Display All Regions with Vehicles\n"
            <<"6. End Program\n";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: add_region(&fleet); break;
            case 2: add_vehicle(&fleet); break;
            case 3: lowest_fuellevel(&fleet); break;
            case 4: remove_inactiveVeh(&fleet); break;
            case 5: display(&fleet); break;
            case 6: break;
            default: cout << "Invalid option! Try again.\n";
        }
    } while (option != 6);

    // Cleanup allocated memory
    for (int i = 0; i < fleet.numReg; i++) {
        delete[] fleet.region[i].vehicle;
    }
    delete[] fleet.region;
    return 0;
}

void input_data(FleetManager* fleet) {
    cout << "Enter the number of regions: ";
    cin >> fleet->numReg;
    cin.ignore();

    fleet->region = new Region[fleet->numReg];
    for (int i = 0; i < fleet->numReg; i++) {
        cout << "Enter the name of Region " << i + 1 << ": ";
        getline(cin, fleet->region[i].regName);
        cout << "Enter the number of vehicles in this region: ";
        cin >> fleet->region[i].numVeh;
        cin.ignore();

        fleet->region[i].vehicle = new Vehicle[fleet->region[i].numVeh];
        for (int j = 0; j < fleet->region[i].numVeh; j++) {
            cout << "Vehicle " << j + 1 << "\n";
            cout << "Vehicle Id: "; getline(cin, fleet->region[i].vehicle[j].Id);
            cout << "Fuel Level: "; cin >> fleet->region[i].vehicle[j].Fuel_level;
            cin.ignore();
            time(&(fleet->region[i].vehicle[j].Last_updated));
        }
    }
    sort_vehicles(fleet);
}

void sort_vehicles(FleetManager* fleet) {
    for (int i = 0; i < fleet->numReg; i++) {
        for (int j = 0; j < fleet->region[i].numVeh - 1; j++) {
            for (int k = 0; k < fleet->region[i].numVeh - j - 1; k++) {
                if (fleet->region[i].vehicle[k].Fuel_level > fleet->region[i].vehicle[k + 1].Fuel_level) {
                    swap(fleet->region[i].vehicle[k], fleet->region[i].vehicle[k + 1]);
                }
            }
        }
    }
}

void add_region(FleetManager* fleet) {
    Region* reg = new Region[fleet->numReg + 1];

    for (int i = 0; i < fleet->numReg; i++) {
        reg[i] = fleet->region[i];
    }
    delete[] fleet->region;

    cout << "Enter the name of the new region: ";
    getline(cin, reg[fleet->numReg].regName);
    cout << "Enter the number of vehicles in this region: ";
    cin >> reg[fleet->numReg].numVeh;
    cin.ignore();

    add_vehicle_to_region(reg[fleet->numReg], reg[fleet->numReg].numVeh);
    fleet->region = reg;
    fleet->numReg++;
    sort_vehicles(fleet);
}

void add_vehicle_to_region(Region& region, int newVehCount) {
    region.vehicle = new Vehicle[newVehCount];
    for (int i = 0; i < newVehCount; i++) {
        cout << "Vehicle Id: "; getline(cin, region.vehicle[i].Id);
        cout << "Fuel Level: "; cin >> region.vehicle[i].Fuel_level;
        cin.ignore();
        time(&(region.vehicle[i].Last_updated));
    }
}

void add_vehicle(FleetManager* fleet) {
    string name;
    cout << "Enter the region name: ";
    getline(cin, name);

    int index = -1;
    for (int i = 0; i < fleet->numReg; i++) {
        if (fleet->region[i].regName == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Invalid region name!\n";
        return;
    }

    int newVeh;
    cout << "Enter the number of vehicles to add: ";
    cin >> newVeh;
    cin.ignore();

    Vehicle* updatedVehicles = new Vehicle[fleet->region[index].numVeh + newVeh];

    for (int i = 0; i < fleet->region[index].numVeh; i++) {
        updatedVehicles[i] = fleet->region[index].vehicle[i];
    }
    delete[] fleet->region[index].vehicle;

    fleet->region[index].vehicle = updatedVehicles;
    add_vehicle_to_region(fleet->region[index], newVeh);
    fleet->region[index].numVeh += newVeh;

    sort_vehicles(fleet);
}

void lowest_fuellevel(FleetManager* fleet) {
    for (int i = 0; i < fleet->numReg; i++) {
        if (fleet->region[i].numVeh == 0) {
            cout << "No vehicles in " << fleet->region[i].regName << ".\n";
            continue;
        }
        cout << "Lowest Fuel in Region " << fleet->region[i].regName << ":\n";
        cout << "Vehicle Id: " << fleet->region[i].vehicle[0].Id
             << ", Fuel Level: " << fleet->region[i].vehicle[0].Fuel_level << "\n";
    }
}

void remove_inactiveVeh(FleetManager* fleet) {
    int hours;
    cout << "Enter the threshold hours: ";
    cin >> hours;
    cin.ignore();

    time_t now;
    time(&now);

    for (int i = 0; i < fleet->numReg; i++) {
        int count = 0;
        for (int j = 0; j < fleet->region[i].numVeh; j++) {
            if (difftime(now, fleet->region[i].vehicle[j].Last_updated) <= hours * 3600) {
                fleet->region[i].vehicle[count++] = fleet->region[i].vehicle[j];
            }
        }
        fleet->region[i].numVeh = count;
    }
}

void display(FleetManager* fleet) {
    for (int i = 0; i < fleet->numReg; i++) {
        cout << "Region: " << fleet->region[i].regName << "\n";
        for (int j = 0; j < fleet->region[i].numVeh; j++) {
            cout << "  Vehicle Id: " << fleet->region[i].vehicle[j].Id
                 << ", Fuel Level: " << fleet->region[i].vehicle[j].Fuel_level
                 << ", Last Updated: " << ctime(&fleet->region[i].vehicle[j].Last_updated);
        }
        cout << "\n";
    }
}