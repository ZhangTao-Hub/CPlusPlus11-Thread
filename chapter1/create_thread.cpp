#include <iostream>
#include <thread>
#include <string>

void foo(std::string msg)
{
    std::cout << msg << std::endl;
    return;
}

int main()
{
    // 创建线程
    std::thread thread1(foo, "Hello C++ Thread");

    // 主线程等待子线程结束再结束 join()
    thread1.join(); 
    
    return 0;
}