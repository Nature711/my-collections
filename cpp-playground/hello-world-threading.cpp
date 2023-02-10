#include <chrono>
#include <iostream>
#include <string>
#include <thread> //required for multithreading

std::string hello = "Hello"; 
//global variable, initialized before entering main()
//equivalent to using single argument constructor: std::string world("Hello");


void print_hello() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << hello << std::endl;
}

//struct is by default public
//if using class, remember to define operator as public
struct MyLambda { 
  void operator()(std::string name) { 
        std::this_thread::sleep_for(std::chrono::seconds(2));
        name += " from Lambda!";
        std::cout << name << std::endl; //printing a newline then flushing buffer
   }
};

struct MyLambdaCapture {
    std::string world;

    void operator()() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        world += " from Lambda Capture!";
        std::cout << world << std::endl;
    }
};

int main() {
  std::string world("World");

  std::thread thread1(print_hello);
  //creates a thread and starts executing function print_hello(args...)
  //no extra argument passed, so executes print_hello()

  std::thread thread2(
      [](std::string name) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        name += "!";
        std::cout << name << std::endl;
      },
      world);
  //lambda expression: [](args...){function_body...}
  //similar to declaring a function object and passing to thread constructor
  //world is passed as argument to lamdba expression
  //argument passed by value, i.e., string name is a copy
  //(instead of reference of original string)
  //when name is modified in function, the original string in main() is left untouched

  std::thread thread3(MyLambda(), world); //similar to thread2
  std::thread thread4(MyLambdaCapture{world});  //lambda variable capture 
  //i.e., passing additional fields to be stored in function object

  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();

  return 0;
  //scope of main() ends
  //destructor of thread4,3,2,1, then world are called 
  //destructor called in reverse order that they were constructed
}

 /* Questions
 - difference between using {} vs ()
 */