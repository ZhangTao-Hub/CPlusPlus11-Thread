#include <iostream>
#include <thread>
#include <string>

void print_message(const std::string& msg)
{
    std::cout << msg << std::endl;
    return;
}

int main()
{
    std::thread t1(print_message, "Hello, World!");
    t1.detach();

    std::cout << "Message printed in a separate thread." << std::endl;
    return 0;
}