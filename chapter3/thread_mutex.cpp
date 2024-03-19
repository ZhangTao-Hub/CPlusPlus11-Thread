#include <iostream>
#include <thread>
#include <mutex>

int data = 0; // 共享数据
std::mutex mtx; // 互斥锁

void func(){
    for (int i = 0; i < 1000000; i++) {
        mtx.lock(); // 加锁
        ++data;
        mtx.unlock(); // 解锁
    }
}

int main()
{
    std::thread t1(func), t2(func);
    t1.join(); t2.join();
    std::cout << "Data: " << data << std::endl;

    return 0;
}