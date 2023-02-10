#include <iostream>
#include <thread>
using namespace std;

class Calculator {
    int my_val;
public: 
    Calculator() {};
    Calculator(int initial_val): my_val(initial_val) {}

    int operator()(int val) {
        my_val *= val;
        return my_val;
    }
};

class Simple {
public: 
    Simple() {cout << "default contructor called";}
    void operator()() {
        cout << "hello\n";
    }
};

int main() {
    Calculator mul5(5);
    cout << mul5(3) << endl;
    cout << mul5(2) << endl;
    cout << Calculator(1)(2) << endl;

    Simple simp;
    std::thread t1(simp); //declaring and running a thread t with a function object
    std::thread t(Simple()); //declaring a function t (that takes in a single parameter: 
    // a pointer to a function that takes in no parameter and returning a Simple object)
    //and returns a thread
    std::thread t2{Simple()}; //declaring and running a thread t2 with a function object

    std::thread t3([]{
        cout << "hello from lambda\n";
    });

    t1.join();
    t2.join();
    t3.join();
}
