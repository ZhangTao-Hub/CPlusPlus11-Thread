#include <iostream>
#include <thread>

std::thread t;
void foo(int* p)
{
    std::cout << *p << std::endl;
}

void test()
{
    int x = 1;
    t = std::thread(foo, &x);
}

int main()
{
    test();
    t.join();
    return 0;
}