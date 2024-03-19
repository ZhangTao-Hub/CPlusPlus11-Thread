#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool{
private:
    // 线程数组
    std::vector<std::thread> workers;
    // 任务队列
    std::queue<std::function<void()>> tasks;
    // 互斥量
    std::mutex mtx;
    // 条件变量
    std::condition_variable cv;
    // 线程池是否终止
    bool stop;

public:
    // 构造函数
    ThreadPool(size_t numThreads): stop(false){
        for (size_t i = 0; i < numThreads; ++i){
            // 创建线程加入线程数组
            workers.emplace_back([this]() {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lck(mtx);
                        // 等待任务
                        cv.wait(lck, [this]{ return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) {
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    // 执行任务
                    task();
                }
            });
        }      
    }

    // 析构函数
    ~ThreadPool(){
        {
            std::unique_lock<std::mutex> lck(mtx);
            stop = true;
        }
        cv.notify_all();
        for (auto &worker: workers) {
            worker.join();
        }
    }

    // 提交任务
    template<class F, class... Args>
    void enqueue(F &&f, Args &&... args){
        std::function<void()> task(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            std::unique_lock<std::mutex> lck(mtx);
            tasks.emplace(std::move(task));
        }
        cv.notify_one();
    }
};

int main(){
    ThreadPool tp(4);
    for (size_t i = 0; i < 8; i++){
        tp.enqueue([i](){ 
            std::cout << "task : " << i << " is running" << std::endl; 
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "task : " << i << " is done" << std::endl;
        });
    }
    return 0;
}