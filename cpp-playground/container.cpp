#include <iostream>
#include <vector>
using namespace std;

class A { //callable object
int i;
    public: 
        A() { //default constructor
            cout << "default constructor called" << endl;
            i = 0; 
        } 
        A(int val) { //custom constructor
            cout << "custom constructor called, A initialized with i being " << val << endl;
            i = val;
        }
        A(const A& other) {
            // copy constructor
            cout << "copy constructor called, A initialized with i being " << other.i << endl;
            i = other.i;
        }
        A(const A&& other) {
            // move constructor
            cout << "move constructor called, A initialized with i being " << other.i << endl;
            i = std::move(other.i);
        }
        ~A() {
            cout << "destructor called, A with i " << i << " is being destroyed" << endl;

        }
};

int main() {
    vector<A> my_vector;
    // my_vector.push_back(1);
    // my_vector.push_back(A(12));
    

    my_vector.push_back(1);
    //my_vector.push_back(A(2));
    //my_vector.emplace_back(A(2));
}
