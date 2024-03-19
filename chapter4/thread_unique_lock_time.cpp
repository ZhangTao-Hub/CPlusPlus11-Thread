#include <iostream>
#include <thread>
#include <mutex>

std::timed_mutex mtx;
int shared_data = 0;

void foo(){
    for (int i=0; i<5; ++i){
        std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock); // 构造但不加锁
        if (lock.try_lock_for(std::chrono::seconds(1)) ){ // 尝试在1秒内获取锁
            std::this_thread::sleep_for(std::chrono::seconds(2)); // 当前线程等待2s
            shared_data++;
        }
    }
}

int main(){
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();

    std::cout << "shared_data: " << shared_data << std::endl;
    return 0;
}