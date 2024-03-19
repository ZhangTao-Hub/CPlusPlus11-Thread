#include <iostream>
#include <thread>

void foo(int& x)
{
    ++x;
}

int main()
{
    std::thread t(foo, 1); // 临时变量被释放
    t.join();
    std::cout << "x = " << x << std::endl;
    return 0;
}