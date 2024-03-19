#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable g_cv;
std::queue<int> g_queue;

void consumer(){
    while (1) {
        std::unique_lock<std::mutex> lck(mtx);
        // 当任务队列中无任务时，需要阻塞
        g_cv.wait(lck, [](){ return !g_queue.empty(); });
        std::cout << "consumer : " << g_queue.front() << std::endl;
        g_queue.pop();
    }
}

void producer(){
    for (int i=0; i<10; ++i){
        {
            std::unique_lock<std::mutex> lck(mtx);
            // 向任务队列中添加任务
            g_queue.push(i);
            std::cout << "producer : " << i << std::endl;
        }
        
        // 任务队列有任务时，需要通知消费者
        g_cv.notify_one();
        // 模拟耗时
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }
}

int main(){

    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}