#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;
int global_sum = 0;     


void partial_sum(const std::vector<int>& data, int start, int end) {
    int local_sum = 0;
    for (int i = start; i < end; ++i) {
        local_sum += data[i];
    }


    std::lock_guard<std::mutex> lock(mtx);
    global_sum += local_sum;
}

int main() {
    std::vector<int> data;


    for (int i = 1; i <= 100; ++i) {
        data.push_back(i);
    }

    int num_threads = 4;
    int chunk_size = data.size() / num_threads;

    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? data.size() : start + chunk_size;

        threads.push_back(std::thread(partial_sum, std::cref(data), start, end));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Tong vector: " << global_sum << std::endl;

    return 0;
}
 