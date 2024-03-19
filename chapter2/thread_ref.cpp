#include <iostream>
#include <thread>

void foo(int& x)
{
    x++;
}

int main()
{   
    int x = 0;
    std::thread t(foo, std::ref(x)); // 创建线程，并传入x的引用
    t.join(); // 等待线程结束
    std::cout << x << std::endl;
    return 0;
}