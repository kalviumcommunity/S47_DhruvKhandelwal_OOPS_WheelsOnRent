#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

class Vehicle{
    private:
        string type;
        int price;
        string color;

    public:
        string get_type(){
            return type;
        }
        
        int get_price(){
            return price;
        }
        
        string get_color(){
            return color;
        }
};

class Customer{
    private:
        string name;
        int age;
        string address;
    public:
        string get_name(){
            return name;
        }
        int get_age(){
            return age;
        }
        string get_address(){
            return address;
        }
};
int main(){
    

    return 0;
}