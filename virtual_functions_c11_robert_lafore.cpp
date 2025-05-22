// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Base {
private:
    int value;  // Private member variable
    string name;
public:

    Base(int val = 0, string name="default") : value(val), name(name) {
        cout <<"STD:: constuctor" << this << " " << this->name << endl;
    }

    // Setter function to update value
    void setValue(int val) {
        value = val;
    }

    // Getter function to retrieve value
    int getValue() const {
        return value;
    }
    
    // copy 
    Base(const Base &a) {
    //Base(const Base a) {    Compiler throws error not necessary
        value = a.value;
        name = a.name;
        cout <<"STD:: copy constructor" << this << " " << this->name << endl;
    }
    
    // assignment
    void operator =(const Base &a) {
    //void operator =(const Base a) {   NEVER USE this, compiler won't throw error but this is unnecessary 
        value = a.value;
        name = a.name;
        cout <<"STD:: = overloading" << this << " " << this->name << endl;
    }
    
    // base destructor
    ~Base() {
        cout <<"STD::  destructor" << this << " " << this->name << endl;
    }
    
};

int main() {
 //------------------------------
#if 1
   // creates one object --> Copy Elision
   // you can disable by "-fno-elide-constructors"
    Base obj = Base(2);
#endif
//------------------------------
#if 0
    Base obj2;  // Create an object of Base
    obj2 =  Base(2,"name"); // Set value
    
#endif
    
//------------------------------

    //cout << "Value: " << obj.getValue() << endl;  // Get and print value
    return 0;
}
