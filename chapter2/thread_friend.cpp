#include <iostream>
#include <thread>

class MyClass{
    friend void test();
private:
    void func(){
        std::cout << "Hello from thread" << std::endl;
    }
};

void test(){
    std::shared_ptr<MyClass> p = std::make_shared<MyClass>();
    std::thread t(&MyClass::func, p);
    t.join();
}

int main()
{
    test();
    return 0;
}