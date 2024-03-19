#include <iostream>
#include <thread>
#include <mutex>

int shared_data = 0;
std::mutex mutex;
void foo(){
    // 构造时, 互斥量锁定; 析构时, 互斥量解锁
    std::lock_guard<std::mutex> lock(mutex);
    shared_data++;
}

int main(){

    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
    std::cout << "shared_data = " << shared_data << std::endl;
    return 0;
}