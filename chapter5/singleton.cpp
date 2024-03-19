#include <iostream>
#include <string>

class Singleton{
    private:
        Singleton(){}
    public:
        Singleton(const Singleton& other) = delete;
        Singleton& operator=(const Singleton& other) = delete;

        static Singleton& getInstance(){
            Singleton *instance = nullptr;
            if(instance == nullptr){
                instance = new Singleton();
            }
            return *instance;
        }

        void printMsg(std::string msg) {
            std::cout << __TIME__ << " " << msg << std::endl;
        }
};

int main(){
    Singleton::getInstance().printMsg("Hello C++");
    return 0;
}