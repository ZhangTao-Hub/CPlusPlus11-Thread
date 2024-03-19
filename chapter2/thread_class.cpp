#include <iostream>
#include <thread>

class MyClass
{
public:
    void func()
    {
        std::cout << "Hello, World!" << std::endl;
    }
};

int main()
{
    MyClass obj;
    std::thread t(&MyClass::func, &obj);
    // 等待线程结束
    t.join();
    return 0;
}