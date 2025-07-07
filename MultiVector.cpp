#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;          // mutex để bảo vệ tổng toàn cục
int global_sum = 0;      // tổng toàn cục

// Hàm xử lý 1 đoạn vector: [start, end)
void partial_sum(const std::vector<int>& data, int start, int end) {
    int local_sum = 0;
    for (int i = start; i < end; ++i) {
        local_sum += data[i];
    }

    // Cập nhật vào tổng toàn cục (bảo vệ bằng mutex)
    std::lock_guard<std::mutex> lock(mtx);
    global_sum += local_sum;
}

int main() {
    std::vector<int> data;

    // Tạo dữ liệu mẫu: 1 đến 100
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
 