#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Vehicle Class Hierarchy
class Vehicle {
protected:
    string type;
    int price;
    string color;

public:
    Vehicle(string type, int price, string color) : type(type), price(price), color(color) {}

    virtual ~Vehicle() {
        cout << "Vehicle object is destroyed" << endl;
    }

    virtual void print_details() const = 0;
};

// Managers for Vehicle Count
class VehicleManager {
private:
    static int vehicle_count;

public:
    static void increment_count() {
        vehicle_count++;
    }

    static int get_vehicle_count() {
        return vehicle_count;
    }
};

int VehicleManager::vehicle_count = 0;

// Car Class
class Car : public Vehicle {
public:
    Car(string color, int price) : Vehicle("Car", price, color) {
        VehicleManager::increment_count();
    }

    void print_details() const override {
        cout << "Car Details:\n"
             << "Type: " << type << "\n"
             << "Price: " << price << "\n"
             << "Color: " << color << "\n";
    }
};

// Truck Class
class Truck : public Vehicle {
public:
    Truck(string color, int price) : Vehicle("Truck", price, color) {
        VehicleManager::increment_count();
    }

    void print_details() const override {
        cout << "Truck Details:\n"
             << "Type: " << type << "\n"
             << "Price: " << price << "\n"
             << "Color: " << color << "\n";
    }
};

// SUV Class
class SUV : public Vehicle {
public:
    SUV(string color, int price) : Vehicle("SUV", price, color) {
        VehicleManager::increment_count();
    }

    void print_details() const override {
        cout << "SUV Details:\n"
             << "Type: " << type << "\n"
             << "Price: " << price << "\n"
             << "Color: " << color << "\n";
    }
};

// Customer Class Hierarchy
class Customer {
protected:
    string name;
    int age;
    string address;

public:
    Customer(string name, int age, string address) : name(name), age(age), address(address) {}

    virtual ~Customer() {
        cout << "Customer object is destroyed" << endl;
    }

    virtual void print_details() const = 0;
};

// Managers for Customer Count
class CustomerManager {
private:
    static int customer_count;

public:
    static void increment_count() {
        customer_count++;
    }

    static int get_customer_count() {
        return customer_count;
    }
};

int CustomerManager::customer_count = 0;

// Premium Customer Class
class PremiumCustomer : public Customer {
private:
    double discount_rate;

public:
    PremiumCustomer(string name, int age, string address, double discount_rate)
        : Customer(name, age, address), discount_rate(discount_rate) {
        CustomerManager::increment_count();
    }

    void print_details() const override {
        cout << "Premium Customer Details:\n"
             << "Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Address: " << address << "\n"
             << "Discount Rate: " << discount_rate * 100 << "%\n";
    }
};

// Regular Customer Class
class RegularCustomer : public Customer {
public:
    RegularCustomer(string name, int age, string address) : Customer(name, age, address) {
        CustomerManager::increment_count();
    }

    void print_details() const override {
        cout << "Regular Customer Details:\n"
             << "Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Address: " << address << "\n";
    }
};

// Main Function
int main() {
    // Demonstrating polymorphism with Vehicle objects
    vector<Vehicle*> vehicles = {
        new Car("Red", 100000),
        new Truck("Blue", 200000),
        new SUV("Green", 150000)
    };

    for (size_t i = 0; i < vehicles.size(); ++i) {
        cout << "Vehicle " << i + 1 << ":\n";
        vehicles[i]->print_details();
        cout << "\n";
    }

    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    // Demonstrating polymorphism with Customer objects
    vector<Customer*> customers = {
        new PremiumCustomer("Alice", 28, "789 Maple St.", 0.15), // 15% discount
        new RegularCustomer("Bob", 32, "321 Pine St.")
    };

    for (size_t i = 0; i < customers.size(); ++i) {
        cout << "Customer " << i + 1 << ":\n";
        customers[i]->print_details();
        cout << "\n";
    }

    for (auto customer : customers) {
        delete customer;
    }

    cout << "\nTotal Vehicles: " << VehicleManager::get_vehicle_count() << endl;
    cout << "Total Customers: " << CustomerManager::get_customer_count() << endl;

    return 0;
}
