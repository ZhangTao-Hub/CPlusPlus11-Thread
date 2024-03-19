#include <iostream>
#include <thread>
#include <memory>

class MyClass
{
    public:
        void func() 
        {
            std::cout << "start : " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));   
            std::cout << "end : " << std::this_thread::get_id() << std::endl;
        }
};

int main()
{
    std::shared_ptr<MyClass> p = std::make_shared<MyClass>();
    std::thread t(&MyClass::func, p);
    t.join();
    return 0;
}