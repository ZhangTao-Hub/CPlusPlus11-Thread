#include <iostream>
#include <future>

int foo(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 42;
}

int main(){
    std::future<int> future_result = std::async(std::launch::async, foo);
    std::cout << foo() << std::endl; // 调用foo()，但不会阻塞
    // 获取异步操作的结果
    std::cout << future_result.get() << std::endl;
    return 0;
}