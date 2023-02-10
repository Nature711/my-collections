//compile: g++ -pthread -o threads threads.cc

#include <iostream>
#include <thread>

void hello() {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "hello concurrent world from thread " << this_id << "\n";
}

int main() {
    std::thread t1(hello);
    std::thread t2(hello);
    t1.join();
    t2.join();
}