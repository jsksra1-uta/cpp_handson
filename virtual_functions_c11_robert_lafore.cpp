// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


//**Summary:**  
//- **Copy constructor:** Used for initialization of a new object.
//- **Assignment operator:** Used for assigning to an existing object.
//They are different functions and serve different purposes!

//Default assignment/copy: Shallow copy (pointer copied, not data).
//Custom assignment/copy: Needed for deep copy (duplicate the data).


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

#if 1
    // copy 
    Base(const Base &a) {
    //Base(const Base a) {    Compiler throws error not necessary
        value = a.value;
        name = a.name;
        cout <<"STD:: copy constructor" << " from:" << &a <<  " "<< " to: " << this << this->name <<endl;
    }
    
    // assignment
    #if 0
    // doesn't support chain assignment a=b=c
    void operator =(const Base &a) {
    //void operator =(const Base a) {   NEVER USE this, compiler won't throw error but this is unnecessary 
        value = a.value;
        name = a.name;
        cout <<"STD:: = constructor" << " from:" << &a <<  " "<< " to: " << this << this->name <<endl;
    }
    #else
    // assignment creates unnecessary copy
    Base operator =(const Base &a) {
        value = a.value;
        name = a.name;
        cout <<"STD:: = constructor" << " from:" << &a <<  " "<< " to: " << this << this->name <<endl;
        return *this;
    }
    #endif
#endif
#if 0
    // copy 
    Base(const Base &a) {
        value = a.value;
        name = a.name;
        cout <<"STD:: efficient copy constructor" << " from:" << &a <<  " "<< " to: " << this << this->name <<endl;
    }
    // assignment
    Base& operator =(const Base &a) {
        if (this != &a) {
            value = a.value;
            name = a.name;
            cout <<"STD:: efficient = overloading" << " from:" << &a <<  " "<< " to: " << this << this->name <<endl;
        }
        return *this;
    }
#endif
#if 0
    //you can prohibit copy constructor and assignment operator by making them private
    private:
    Base(const Base &a);
    Base operator =(const Base &a);
#endif
    
    // base destructor
    ~Base() {
        cout <<"STD::  destructor" << this << " " << this->name << endl;
    }
    

};

int main() {
 //------------------------------
#if 0
   // creates one object --> Copy Elision
   // you can disable by "-fno-elide-constructors"
    Base obj = Base(2);
#endif
//------------------------------
#if 0
    Base obj2;  // Create an object of Base
    obj2 =  Base(2,"name"); // Set value
    
#endif

#if 1
    Base obj1,obj2,obj3;  // Create an object of Base
    obj1 =  Base(2,"name"); // Set value
    cout << "Focus here =============" << endl;
    obj3 = obj2 = obj1; // Set value
    cout << "Focus end =============" << endl;
    
#endif
    
//------------------------------

    //cout << "Value: " << obj.getValue() << endl;  // Get and print value
    return 0;
}
