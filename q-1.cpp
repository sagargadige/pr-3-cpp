#include<iostream>
using namespace std;

// parent class 
class Vehicle{
    public:
        int vehicleID;
        string manufacture;
        string model;
        int year;
    Vehicle(){
        
    }
};
// derive class
class Car : public Vehicle{
    private:
        string fuelType;
};
class ElectricCar : public Car{
    private:
        string batteryCapacity;
};
class Aircraft{
    private:
        string flightRange;
};
class FlyingCar : public Car , public Aircraft{
    private:
        
};
class SportsCar : public ElectricCar{
    private:
        string topSpeed;

};
class Sedan : public Car{

};

const int MAX_VEHICLES = 100;

class Vehicle
{
protected:
    int vehicleID;
    string manufacture;
    string model;
    int year;
    static int totalVehicles;
    int typeID; // 1 = Car, 2 = ElectricCar, 3 = Motorcycle

public:
    Vehicle(int id = 0, string manu = "", string mod = "", int yr = 0, int type = 0)
        : vehicleID(id), manufacture(manu), model(mod), year(yr), typeID(type)
    {
        totalVehicles++;
    }

    void displayDetails()
    {
        cout << "Vehicle ID: " << vehicleID << "\nManufacturer: " << manufacture
             << "\nModel: " << model << "\nYear: " << year << endl;
    }

    int getID() { return vehicleID; }
    int getTypeID() { return typeID; }

    static int getTotalVehicles() { return totalVehicles; }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr, 1), fuelType(fuel) {}

    void showCarDetails()
    {
        displayDetails();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery)
    {
        typeID = 2;
    }

    void showElectricDetails()
    {
        displayDetails();
        cout << "Fuel Type: " << fuelType << "\nBattery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class Motorcycle : public Vehicle
{
    bool hasSidecar;

public:
    Motorcycle(int id, string manu, string mod, int yr, bool sidecar)
        : Vehicle(id, manu, mod, yr, 3), hasSidecar(sidecar) {}

    void showMotorcycleDetails()
    {
        displayDetails();
        cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

int main()
{
    Vehicle *vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    int choice;

    do
    {
        cout << "\n--- Vehicle Management System ---\n";
        cout << "1. Add Vehicle\n2. View All Vehicles\n3. Search by ID\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (vehicleCount >= MAX_VEHICLES)
            {
                cout << "Vehicle storage full!" << endl;
                break;
            }

            int type, id, year, battery;
            string manu, mod, fuel;
            bool sidecar;

            cout << "Select Vehicle Type:\n1. Car\n2. Electric Car\n3. Motorcycle\n";
            cin >> type;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> year;

            if (type == 1)
            {
                cout << "Enter Fuel Type (e.g., Petrol, Diesel): ";
                cin >> fuel;
                vehicles[vehicleCount++] = new Car(id, manu, mod, year, fuel);
            }
            else if (type == 2)
            {
                cout << "Enter Battery Capacity (in kWh): ";
                cin >> battery;
                vehicles[vehicleCount++] = new ElectricCar(id, manu, mod, year, "Electric", battery);
            }
            else if (type == 3)
            {
                cout << "Has Sidecar (1 for Yes, 0 for No): ";
                cin >> sidecar;
                vehicles[vehicleCount++] = new Motorcycle(id, manu, mod, year, sidecar);
            }
            else
            {
                cout << "Invalid type!" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "\n--- All Vehicles ---\n";
            for (int i = 0; i < vehicleCount; ++i)
            {
                int type = vehicles[i]->getTypeID();
                if (type == 1)
                {
                    ((Car *)vehicles[i])->showCarDetails();
                }
                else if (type == 2)
                {
                    ((ElectricCar *)vehicles[i])->showElectricDetails();
                }
                else if (type == 3)
                {
                    ((Motorcycle *)vehicles[i])->showMotorcycleDetails();
                }
                cout << "-------------------\n";
            }
            cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << endl;
            break;
        }

        case 3:
        {
            int searchID;
            cout << "Enter Vehicle ID to search: ";
            cin >> searchID;
            bool found = false;
            for (int i = 0; i < vehicleCount; ++i)
            {
                if (vehicles[i]->getID() == searchID)
                {
                    int type = vehicles[i]->getTypeID();
                    if (type == 1)
                        ((Car *)vehicles[i])->showCarDetails();
                    else if (type == 2)
                        ((ElectricCar *)vehicles[i])->showElectricDetails();
                    else if (type == 3)
                        ((Motorcycle *)vehicles[i])->showMotorcycleDetails();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Vehicle not found!" << endl;
            break;
        }

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Please enter a valid number!" << endl;
        }
    } while (choice != 4);

    for (int i = 0; i < vehicleCount; ++i)
        delete vehicles[i];

    return 0;
}



int main()
{
    int n;
    do{
        cout<<"Enter 1 For Add Vehicle"<<endl;
        cout<<"Enter 2 For View for all Vehicle"<<endl;
        cout<<"Enter 3 Search Vehicle by ID"<<endl;
        cout<<"Enter 4 For Exit"<<endl;

        switch (n){
            case 1 :
            break;
            case 2 :
            break;
            case 3 :
            break;
            case 4 :
            break;
            default:
                cout<<"Please Enter a valid Number !";
        }
    }while(n!=0);
    return 0;
}