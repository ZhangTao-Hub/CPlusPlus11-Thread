#include <iostream>
#include <thread>
#include <string>

void print_message(const std::string& message)
{
    std::cout << message << std::endl;
    return;
}

void increment(int& x)
{
    ++x;
    return;
}

int main()
{
    std::string msg = "Hello, World!";
    std::thread t1(print_message, std::ref(msg));
    t1.join();

    int x = 0;
    // Pass by reference to ensure that x is correctly modified within the thread
    std::thread t2(increment, std::ref(x)); 
    t2.join();

    std::cout << "Final value of x: " << x << std::endl;
    return 0;
}