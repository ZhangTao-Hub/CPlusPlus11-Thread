#include <iostream>
#include <future>

void foo(std::promise<int> &p){
    p.set_value(100);
}

int main(){
    // 创建promise对象
    std::promise<int> p;
    // 获取future对象
    std::future<int> future_result = p.get_future();
    // 创建线程
    std::thread t(foo, std::ref(p));
    // 等待子线程执行完毕
    t.join();

    std::cout << future_result.get() << std::endl;
    return 0;
}