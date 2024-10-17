#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string type;
    int price;
    string color;
    static int vehicle_count;

public:
    Vehicle(string type, int price, string color) {
        this->type = type;
        this->price = price;
        this->color = color;
        vehicle_count++;
    }

    string get_type() {
        return type;
    }

    void set_type(string type) {
        this->type = type;
    }

    int get_price() {
        return price;
    }

    void set_price(int price) {
        this->price = price;
    }

    string get_color() {
        return color;
    }

    void set_color(string color) {
        this->color = color;
    }

    static int get_vehicle_count() {
        return vehicle_count;
    }

    void print_details() {
        cout << "Type: " << type << endl;
        cout << "Price: " << price << endl;
        cout << "Color: " << color << endl;
    }
};

int Vehicle::vehicle_count = 0;

class Customer {
private:
    string name;
    int age;
    string address;
    static int customer_count;

public:
    Customer(string name, int age, string address) {
        this->name = name;
        this->age = age;
        this->address = address;
        customer_count++;
    }

    string get_name() {
        return name;
    }

    void set_name(string name) {
        this->name = name;
    }

    int get_age() {
        return age;
    }

    void set_age(int age) {
        this->age = age;
    }

    string get_address() {
        return address;
    }

    void set_address(string address) {
        this->address = address;
    }

    static int get_customer_count() {
        return customer_count;
    }

    void print_details() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

int Customer::customer_count = 0;

int main() {
    Vehicle vehicles[3] = {
        Vehicle("Car", 100000, "Red"),
        Vehicle("Truck", 200000, "Blue"),
        Vehicle("SUV", 150000, "Green")
    };

    vehicles[0].set_type("Convertible");
    vehicles[1].set_price(250000);
    vehicles[2].set_color("Yellow");

    for (int i = 0; i < 3; i++) {
        cout << "Vehicle " << i + 1 << ":\n";
        vehicles[i].print_details();  
        cout << endl;
    }

    Customer* customer = new Customer("John", 30, "123 Main St.");

    customer->set_name("Michael");
    customer->set_age(35);
    customer->set_address("456 Oak St.");

    cout << "Customer Details:\n";
    customer->print_details();  

    cout << "\nTotal Vehicles: " << Vehicle::get_vehicle_count() << endl;
    cout << "Total Customers: " << Customer::get_customer_count() << endl;

    delete customer;
    customer = nullptr;

    return 0;
}
