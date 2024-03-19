#include <iostream>
#include <thread>
#include <mutex>

int shared_data = 0;
std::mutex mtx;

void foo(){
    for (int i=0; i<2; ++i){
        std::unique_lock<std::mutex> lck(mtx);
        ++shared_data;
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