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
    std::thread t1(print_message, "Hello from thread 1!");
    if (t1.joinable())
    {
        t1.join();
    }

    std::cout << "Thread joined" << std::endl;
    return 0;
}