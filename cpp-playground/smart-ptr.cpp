#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <thread> 
using namespace std;
//compile: clang++ -pthread -fsanitize=thread smart-ptr.cpp -o smart-ptr

class MyIntClass {
    public:
        int data = 0;
        MyIntClass(int i): data(i) {
            cout << "my int class initialized with data " << i << endl;
        };
        ~MyIntClass() {
            cout << "my int class with data " << data << " gets destroyed" << endl;
        }
};

class MyIntPtrClass {
    int* intPtr = new int(0);
    public:
        MyIntPtrClass(int i): intPtr(new int(i)) {
            cout << "my intptr class initialized with data " << i << endl;
        };
        ~MyIntPtrClass() {
            cout << "my int class with data " << *intPtr << " gets destroyed" << endl;
            //still needs to free the dynamically allocated memory 
            delete intPtr;
        }
};

void readThread(shared_ptr<MyIntClass> sptr) {
    cout << "read value " << sptr->data << endl;
}


void writeThread(shared_ptr<MyIntClass> sptr) {
    (sptr->data)++;
    cout << "increment value to" << sptr->data << endl;
}


int main()
{
    int* foo = new int(0);
    cout << "value of foo is " << *foo << endl;
    delete foo; 
    //without delete -- address sanitizer: 4 bytes leaked in 1 allocation

    unique_ptr<MyIntClass> uptr1 = make_unique<MyIntClass>(1);
    unique_ptr<MyIntPtrClass> uptr2 = make_unique<MyIntPtrClass>(1);
    //even though the object pointed to by the smart pointer gets destroyed, the dynamically allocated memory created 
    //by that object still needs to be manually freed (in object's destructor)

    shared_ptr<MyIntClass> sptr1 = make_shared<MyIntClass>(3);
    
    std::thread { readThread, sptr1}.detach();
    std::thread { writeThread, sptr1 }.detach();
    //data race

} 



