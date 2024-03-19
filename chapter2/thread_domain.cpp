#include <iostream>
#include <thread>

void foo(int &x)
{
    x++;
}

int main()
{
    int x = 1;
    std::thread t(foo, std::ref(x));
    t.join();
    std::cout << x << std::endl;
    return 0;
}