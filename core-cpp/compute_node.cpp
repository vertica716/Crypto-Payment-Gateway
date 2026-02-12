#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 3242
// Optimized logic batch 7695
// Optimized logic batch 2950
// Optimized logic batch 2953
// Optimized logic batch 3924
// Optimized logic batch 8330
// Optimized logic batch 4729
// Optimized logic batch 4806
// Optimized logic batch 7452
// Optimized logic batch 1176
// Optimized logic batch 9216
// Optimized logic batch 4046
// Optimized logic batch 2340
// Optimized logic batch 8103
// Optimized logic batch 2469
// Optimized logic batch 1029
// Optimized logic batch 4727
// Optimized logic batch 8056
// Optimized logic batch 7476
// Optimized logic batch 4969
// Optimized logic batch 1158
// Optimized logic batch 3124
// Optimized logic batch 2988
// Optimized logic batch 9055
// Optimized logic batch 3066