#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2;

void func1(){
    for (int i = 0; i < 5000; ++ i) {
        m1.lock();
        m2.lock();
        m1.unlock();
        m2.unlock();
    }
}

void func2(){
    for (int i = 0; i < 5000; ++ i) {
        m1.lock();
        m2.lock();
        m1.unlock();
        m2.unlock();
    }
}

int main(){
    std::thread t1(func1);
    std::thread t2(func2);
    t1.join();
    t2.join();

    std::cout << "Done" << std::endl;
    return 0;
}