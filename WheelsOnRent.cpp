#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers
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

    virtual int calculate_tax() const = 0; 
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

// Tax Calculation Strategy
class TaxCalculator {
public:
    virtual int calculate_tax(int price) const = 0;
};

// Concrete Tax Strategies
class CarTaxCalculator : public TaxCalculator {
public:
    int calculate_tax(int price) const override {
        return static_cast<int>(price * 0.10); // 10% tax for cars
    }
};

class TruckTaxCalculator : public TaxCalculator {
public:
    int calculate_tax(int price) const override {
        return static_cast<int>(price * 0.15); // 15% tax for trucks
    }
};

class SUVTaxCalculator : public TaxCalculator {
public:
    int calculate_tax(int price) const override {
        return static_cast<int>(price * 0.12); // 12% tax for SUVs
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

// Truck Class
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

// SUV Class
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

    virtual double calculate_discount(double amount) const = 0; // Open for extension
};

// Discount Calculation Strategy
class DiscountStrategy {
public:
    virtual double calculate_discount(double amount) const = 0;
};

// Concrete Discount Strategies
class PremiumDiscount : public DiscountStrategy {
public:
    double calculate_discount(double amount) const override {
        return amount * 0.15; // 15% discount
    }
};

class RegularDiscount : public DiscountStrategy {
public:
    double calculate_discount(double amount) const override {
        return amount * 0.05; // 5% discount
    }
};

// Premium Customer Class
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

// Regular Customer Class
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
        new PremiumCustomer("Alice", 28, "789 Maple St."),
        new RegularCustomer("Bob", 32, "321 Pine St.")
    };

    for (size_t i = 0; i < customers.size(); ++i) {
        cout << "Customer " << i + 1 << ":\n";
        customers[i]->print_details();
        cout << "Discount on $1000: $" << customers[i]->calculate_discount(1000) << "\n";
        cout << "\n";
    }

    for (auto customer : customers) {
        delete customer;
    }

    cout << "\nTotal Vehicles: " << VehicleManager::get_vehicle_count() << endl;

    return 0;
}
