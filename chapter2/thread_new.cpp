#include <iostream>
#include <thread>

std::thread t;
void foo(int* p)
{
    std::cout << *p << std::endl;
    delete p;
}

void test()
{
    int *x = new int(1);
    t = std::thread(foo, x);
}

int main()
{
    test();
    t.join();
    return 0;
}