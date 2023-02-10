#include <iostream>
using namespace std;

class boVector {
    int size;
    double* arr;
    public:
        boVector() {
            cout << "default constructor called\n";
            size = 10;
            arr = new double[size];
            for (int i = 0; i < size; i++) arr[i] = i;
        }
        boVector(const boVector& rhs) { //copy constructor
            cout << "copy constructor called\n";
            size = rhs.size;
            arr = new double[size]; //dynamically allocated memory
            for (int i = 0; i < size; i++) arr[i] = rhs.arr[i]; //expensive deep copy
        }
        boVector(boVector&& rhs) { //move constructor
            cout << "move constructor called\n";
            size = rhs.size;
            arr = rhs.arr;
            rhs.arr = nullptr; //otherwise when rhs is destroyed, destructor will delete this arr
            //cheap shallow copy
        }
        ~boVector() { 
            cout << "destructor called\n";
            delete arr; 
        }
};

void foo(boVector v) {
    cout << "foo by value\n";
}

void foo_by_ref(boVector v) {
    cout << "foo by ref move\n";
}

// void foo(boVector&& v) {
//     cout << "foo by ref\n";
// }


int main() {
    boVector bv = boVector();
    // boVector copied = bv;
    // boVector& ref = bv;
    // boVector&& reff = boVector();
    // foo(bv);
    // foo(boVector());
    // foo(copied);
    // foo(ref);
    // foo(reff);
    foo(bv); //call copy constructor
    foo_by_ref(std::move(bv));
}