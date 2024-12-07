#include <iostream>
#include <string>
#include <vector>
#include <memory> 
using namespace std;

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

    virtual int calculate_tax() const = 0;
};

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

class TaxCalculator {
public:
    virtual int calculate_tax(int price) const = 0;
};

class CarTaxCalculator : public TaxCalculator {
public:
    int calculate_tax(int price) const override {
        return static_cast<int>(price * 0.10); 
    }
};

class TruckTaxCalculator : public TaxCalculator {
public:
    int calculate_tax(int price) const override {
        return static_cast<int>(price * 0.15); 
    }
};

class SUVTaxCalculator : public TaxCalculator {
public:
    int calculate_tax(int price) const override {
        return static_cast<int>(price * 0.12); 
    }
};

// Car Class
class Car : public Vehicle {
    unique_ptr<TaxCalculator> tax_calculator;

public:
    Car(string color, int price) : Vehicle("Car", price, color), tax_calculator(make_unique<CarTaxCalculator>()) {
        VehicleManager::increment_count();
    }

    void print_details() const override {
        cout << "Car Details:\n"
             << "Type: " << type << "\n"
             << "Price: " << price << "\n"
             << "Color: " << color << "\n"
             << "Tax: " << calculate_tax() << "\n";
    }

    int calculate_tax() const override {
        return tax_calculator->calculate_tax(price);
    }
};

class Truck : public Vehicle {
    unique_ptr<TaxCalculator> tax_calculator;

public:
    Truck(string color, int price) : Vehicle("Truck", price, color), tax_calculator(make_unique<TruckTaxCalculator>()) {
        VehicleManager::increment_count();
    }

    void print_details() const override {
        cout << "Truck Details:\n"
             << "Type: " << type << "\n"
             << "Price: " << price << "\n"
             << "Color: " << color << "\n"
             << "Tax: " << calculate_tax() << "\n";
    }

    int calculate_tax() const override {
        return tax_calculator->calculate_tax(price);
    }
};

class SUV : public Vehicle {
    unique_ptr<TaxCalculator> tax_calculator;

public:
    SUV(string color, int price) : Vehicle("SUV", price, color), tax_calculator(make_unique<SUVTaxCalculator>()) {
        VehicleManager::increment_count();
    }

    void print_details() const override {
        cout << "SUV Details:\n"
             << "Type: " << type << "\n"
             << "Price: " << price << "\n"
             << "Color: " << color << "\n"
             << "Tax: " << calculate_tax() << "\n";
    }

    int calculate_tax() const override {
        return tax_calculator->calculate_tax(price);
    }
};

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

    virtual double calculate_discount(double amount) const = 0;
};

class DiscountStrategy {
public:
    virtual double calculate_discount(double amount) const = 0;
};

class PremiumDiscount : public DiscountStrategy {
public:
    double calculate_discount(double amount) const override {
        return amount * 0.15;
    }
};

class RegularDiscount : public DiscountStrategy {
public:
    double calculate_discount(double amount) const override {
        return amount * 0.05;
    }
};

class PremiumCustomer : public Customer {
    unique_ptr<DiscountStrategy> discount_strategy;

public:
    PremiumCustomer(string name, int age, string address)
        : Customer(name, age, address), discount_strategy(make_unique<PremiumDiscount>()) {}

    void print_details() const override {
        cout << "Premium Customer Details:\n"
             << "Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Address: " << address << "\n";
    }

    double calculate_discount(double amount) const override {
        return discount_strategy->calculate_discount(amount);
    }
};

class RegularCustomer : public Customer {
    unique_ptr<DiscountStrategy> discount_strategy;

public:
    RegularCustomer(string name, int age, string address)
        : Customer(name, age, address), discount_strategy(make_unique<RegularDiscount>()) {}

    void print_details() const override {
        cout << "Regular Customer Details:\n"
             << "Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Address: " << address << "\n";
    }

    double calculate_discount(double amount) const override {
        return discount_strategy->calculate_discount(amount);
    }
};

int main() {
    vector<unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(make_unique<Car>("Red", 100000));
    vehicles.push_back(make_unique<Truck>("Blue", 200000));
    vehicles.push_back(make_unique<SUV>("Green", 150000));

    for (const auto& vehicle : vehicles) {
        vehicle->print_details();
        cout << "\n";
    }

    vector<unique_ptr<Customer>> customers;
    customers.push_back(make_unique<PremiumCustomer>("Alice", 28, "789 Maple St."));
    customers.push_back(make_unique<RegularCustomer>("Bob", 32, "321 Pine St."));

    for (const auto& customer : customers) {
        customer->print_details();
        cout << "Discount on $1000: $" << customer->calculate_discount(1000) << "\n";
        cout << "\n";
    }

    cout << "Total Vehicles: " << VehicleManager::get_vehicle_count() << endl;

    return 0;
}
