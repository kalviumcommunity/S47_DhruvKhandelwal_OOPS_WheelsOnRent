#include <iostream>
#include <vector>
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

    int get_price() {
        return price;
    }

    string get_color() {
        return color;
    }

    int get_vehicle_count() {
        return vehicle_count;
    }
};


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

    int get_age() {
        return age;
    }

    string get_address() {
        return address;
    }

    int get_customer_count() {
        return customer_count;
    }
};


int Vehicle::vehicle_count = 0;
int Customer::customer_count = 0;

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

    cout << "Vehicle count: " << vehicles->get_vehicle_count() << endl;
    cout << "Customer count: " << customer->get_customer_count() << endl;
    cout<<"Before delete"<<customer<<endl;

    delete customer;
    customer = nullptr;

    cout<<"After delete"<<customer;
    

    return 0;
}
