//compile: g++ -pthread -o threads threads.cc

#include <iostream>
#include <climits>


void divisionByZero() {
    int val = 5; 
    std::cout << "divide by zero result: "  << val / 0 << std::endl;
    //compile time: warning: division by zero -Wdiv-by-zero
    //runtime: floating point exception
}

void indexOutOfBounds() {
    int arr[3] = {1,2,3};
    std::cout << "number at index 3: " << arr[3] << std::endl;
    //no compile time error
    //runtime output: 1586100480 (a random number, different in different runs)
}

void integerOverflow() {
    int val = INT_MAX;
    std::cout << "max int plus one: " << val + 1 << std::endl;
    //no compile time error
    //runtime output: -2147483648 (overflowed result)
}

void nullptrDeference() {
    int* ptr = nullptr;
    std::cout << "deference nullptr: " << *ptr << std::endl;
    //no compile time error
    //runtime output: segmentation fault
}

int main() {
    nullptrDeference();
}