#include <iostream>
using namespace std;

// void print(int i) {
// cout << "print normal " << i << "\n";
// };
//when the compiler is unable to choose between two correctly overloaded functions

void print(int& i) {
cout << "print lvalue " << i << "\n";
};

void print(int&& i) {
cout << "print rvalue " << i << "\n";
};


int main() {
    int val = 1; //val is a lvalue
    print(val); //first print is called
    print(2); //2 is a rvalue, second print is called
};
