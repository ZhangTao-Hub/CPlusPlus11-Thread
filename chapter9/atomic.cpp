#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> data;

void foo(){
    for (int i=0; i<10000; ++i){
        data++;
    }
}

int main(){
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();

    std::cout << "Data: " << data << std::endl;
    std::cout << "Data: " << data.load() << std::endl; // 输出 20000
    data.store(1);
    std::cout << "Data: " << data.load() << std::endl; // 输出 1
    return 0;
}