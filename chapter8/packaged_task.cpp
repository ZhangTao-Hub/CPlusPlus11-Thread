#include <iostream>
#include <future>

int foo(int x){
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时操作
    return x;
}

int main(){

    std::packaged_task<int(int)> task(foo);
    std::future<int> result = task.get_future();
    /*  这里创建了一个新的线程，并在这个线程中执行异步操作。
        由于packaged_task对象是可移动的，
        因此需要使用std::move()函数将task对象转移至新线程中执行。
    */
    std::thread t(std::move(task), 10); // std::move的使用
    t.join();

    std::cout << result.get() << std::endl;
    return 0;
}