#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string type;
    int price;
    string color;
    static int vehicle_count;

public:
    Vehicle() : type(""), price(0), color("") {
        vehicle_count++;
    }

    Vehicle(string type, int price, string color) : type(type), price(price), color(color) {
        vehicle_count++;
    }

    virtual ~Vehicle() {
        cout << "Vehicle object is destroyed" << endl;
    }

    virtual void print_details() const {
        cout << "Type: " << type << endl;
        cout << "Price: " << price << endl;
        cout << "Color: " << color << endl;
    }

    static int get_vehicle_count() {
        return vehicle_count;
    }
};

int Vehicle::vehicle_count = 0;

class Car : public Vehicle {
public:
    Car(string color, int price) : Vehicle("Car", price, color) {}

    void print_details() const override {
        cout << "Car Details:" << endl;
        Vehicle::print_details();
    }
};

class Truck : public Vehicle {
public:
    Truck(string color, int price) : Vehicle("Truck", price, color) {}

    void print_details() const override {
        cout << "Truck Details:" << endl;
        Vehicle::print_details();
    }
};

class SUV : public Vehicle {
public:
    SUV(string color, int price) : Vehicle("SUV", price, color) {}

    void print_details() const override {
        cout << "SUV Details:" << endl;
        Vehicle::print_details();
    }
};

// Base Customer class
class Customer {
protected:
    string name;
    int age;
    string address;
    static int customer_count;

public:
    Customer() : name(""), age(0), address("") {
        customer_count++;
    }

    Customer(string name, int age, string address) : name(name), age(age), address(address) {
        customer_count++;
    }

    virtual ~Customer() {
        cout << "Customer object is destroyed" << endl;
    }

    virtual void print_details() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }

    static int get_customer_count() {
        return customer_count;
    }
};

int Customer::customer_count = 0;

// Subclass for Premium Customer
class PremiumCustomer : public Customer {
private:
    double discount_rate;

public:
    PremiumCustomer(string name, int age, string address, double discount_rate)
        : Customer(name, age, address), discount_rate(discount_rate) {}

    void print_details() const override {
        cout << "Premium Customer Details:" << endl;
        Customer::print_details();
        cout << "Discount Rate: " << discount_rate * 100 << "%" << endl;
    }
};

class RegularCustomer : public Customer {
public:
    RegularCustomer(string name, int age, string address) : Customer(name, age, address) {}

    void print_details() const override {
        cout << "Regular Customer Details:" << endl;
        Customer::print_details();
    }
};

int main() {
    // Demonstrating polymorphism with Vehicle objects
    Vehicle* vehicles[3];
    vehicles[0] = new Car("Red", 100000);
    vehicles[1] = new Truck("Blue", 200000);
    vehicles[2] = new SUV("Green", 150000);

    for (int i = 0; i < 3; i++) {
        cout << "Vehicle " << i + 1 << ":\n";
        vehicles[i]->print_details();  // Polymorphic call
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete vehicles[i];  // Calls the appropriate destructor
    }

    // Demonstrating polymorphism with Customer objects
    Customer* customers[2];
    customers[0] = new PremiumCustomer("Alice", 28, "789 Maple St.", 0.15); // 15% discount
    customers[1] = new RegularCustomer("Bob", 32, "321 Pine St.");

    for (int i = 0; i < 2; i++) {
        cout << "Customer " << i + 1 << ":\n";
        customers[i]->print_details();  // Polymorphic call
        cout << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete customers[i];  // Calls the appropriate destructor
    }

    cout << "\nTotal Vehicles: " << Vehicle::get_vehicle_count() << endl;
    cout << "Total Customers: " << Customer::get_customer_count() << endl;

    return 0;
}
