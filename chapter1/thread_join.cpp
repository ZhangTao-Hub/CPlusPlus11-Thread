#include <iostream>
#include <thread>
#include <string>

void print_message(const std::string& message)
{
    std::cout << message << std::endl;
    return;
}

int main()
{

    std::thread t1(print_message, "Hello from thread 1");
    std::thread t2(print_message, "Hello from thread 2");
    t1.join();
    t2.join();
    return 0;
}