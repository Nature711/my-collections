#include <iostream>
using namespace std;
#include <thread>

//function declarations
int a(); //declaration: declares a function named "a" that takes in no argument and returns an int

int a(int); //overloading function: takes in one argument of type int and returns an int

//function definitions
int a() { 
    cout << "hello from function a()" << endl;
    return 0; 
} 

int a(int i) { 
    cout << "hello from function a(i)" << endl;
    if (i > 0) return i + 1;
    else return i + 2;
} 

class A { //callable object
int i;
    public: 
        A() { //default constructor
            cout << "default constructor called" << endl;
            i = 0; 
        } 
        A(int val) { //custom constructor
            cout << "custom constructor called" << endl;
            i = val;
        }
        void operator()() {
            cout << "hello from A's normal operator" << endl;
        }
        void operator()(int a) {
            cout << "hello from A's overloading operator " << endl;
        }
};

int main() {
    //function calls
    // int res0 = a();
    // cout << "calling a() returns: " << res0 << endl;

    // int res1 = a(0);
    // cout << "calling a(0) returns: "  << res1 << endl;
    a(); //calling the function a()
    a(1); //calling the function a(i)
    A a; //declaring an object of type A (using default constructor)
    a(); //calling the operator of object a
    a(1); //calling the overloading operator of object a

    A b = A(); //creating an object of type A (RHS) and store it in a variable named b
    b(); //calling the operator of b
    A()(); //creating an object of type A (without storing it) and calling the operator of it
    A(1)(2);

    std::thread t1(A()); //declaring a function named t1 that takes in a 
    std::thread t3(A); //declaring a function named t3 that takes in a ???

    /*
    Here, an object of type A is created and passed as an argument to the std::thread constructor, 
    which will launch a new thread and run the operator() function of the A object in the new thread.
    */
    std::thread t2((A())); //launching a thread with callable object A()
    std::thread t4{A()}; //launching a thread with callable object A(), same as above
    t2.join();
    t4.join();
    
    A aa;
    A aaa = A();
    //also can
    std::thread t5(aa); 
    std::thread t6(aaa);
    t5.join();
    t6.join();
}