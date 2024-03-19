#include <iostream>
#include <thread>

void foo(int& x)
{
    std::cout << x << std::endl;
}

int main()
{
    int *x = new int(1);
    std::thread t(foo, *x); // 传递已经释放掉的内存
    delete x;

    t.join();
    return 0;
}
