#include <iostream>
#include <thread>

int data = 0;
void func()
{
    for (int i = 0; i < 1000000; ++ i)
    {
        ++data;
    }
}

int main()
{
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    std::cout << "data: " << data << std::endl; // 输出data的值

}