#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
#include <unistd.h>

std::mutex mu;

// void shared_print(int tid, int i) {
//     mu.lock();
//     cout << "hello from thread " << tid << endl;
//     std::this_thread::sleep_for(std::chrono::microseconds(10000));
//     cout << "thread " << tid << "prints" << i << endl;
//     mu.unlock();
// }

void print_message(int tid) {
    for (int i = 0; i < 100; i++) {
        cout << "hello from thread " << tid << endl;
        std::this_thread::sleep_for(std::chrono::microseconds(10000));
        cout << "thread " << tid << "prints" << i << endl;
        // shared_print(tid, i);
    }
}

int main() {
    std::thread t1(print_message, 1);
    std::thread t2(print_message, 2);

    t1.join();
    t2.join();
}