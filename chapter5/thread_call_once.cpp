#include <iostream>
#include <thread>
#include <string>
#include <mutex>


class Singleton{
    private:
        Singleton(){}
        static Singleton* instance;
        static std::once_flag initFlag;
    public:
        static Singleton& getInstance() {
            std::call_once(initFlag, init);
            return *instance;
        }

        static void init(){
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }

        void printMessage(std::string msg) {
            std::cout << __TIME__ << " " << msg << std::endl;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};

std::once_flag Singleton::initFlag;
Singleton* Singleton::instance = nullptr;

void test() {
    Singleton::getInstance().printMessage("Hello from main");
}

int main(){

    std::thread t1(test);
    std::thread t2(test);
    t1.join();
    t2.join();
    return 0;
}
