#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
private:
    string type;
    int price;
    string color;

public:
    // Default constructor to allow creating arrays of Vehicle objects
    Vehicle() : type(""), price(0), color("") {}

    // Parameterized constructor
    Vehicle(string type, int price, string color) {
        this->type = type;
        this->price = price;
        this->color = color;
    }

    string get_type() {
        return type;
    }

    int get_price() {
        return price;
    }

    string get_color() {
        return color;
    }
};

class Customer {
private:
    string name;
    int age;
    string address;

public:
    Customer(string name, int age, string address) {
        this->name = name;
        this->age = age;
        this->address = address;
    }

    string get_name() {
        return name;
    }

    int get_age() {
        return age;
    }

    string get_address() {
        return address;
    }
};

int main() {
    string type, color;
    int price;

    // Creating an array of 3 Vehicle objects
    Vehicle vehicles[3] = {
        Vehicle("Car", 100000, "Red"),
        Vehicle("Truck", 200000, "Blue"),
        Vehicle("SUV", 150000, "Green")
    };  

    for (int i = 0; i < 3; i++) {
        cout << "Type: " << vehicles[i].get_type() << endl;
        cout << "Price: " << vehicles[i].get_price() << endl;
        cout << "Color: " << vehicles[i].get_color() << endl;
        cout << endl;
    }

    Customer* customer = new Customer("John", 30, "123 Main St.");

    cout << "Name: " << customer->get_name() << endl;
    cout << "Age: " << customer->get_age() << endl;
    cout << "Address: " << customer->get_address() << endl;

    cout<<"Before delete"<<customer<<endl;
    
    delete customer;

    cout<<"After delete"<<customer;
    

    return 0;
}
