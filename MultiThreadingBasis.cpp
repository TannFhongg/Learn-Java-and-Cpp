#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>

// multi threading basis
// thread la luồng, đơn vị nhỏ nhất của CPU scheduler
// thực hiện nhiều công việc cùng 1 lúc, đa lõi
std::mutex mtx;
std::condition_variable cv;
int current = 1;
int MAX = 10;

void printEven()
{
    while (current <= MAX)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
                { return current % 2 == 0; });

        if (current <= MAX)
        {
            std::cout << "Even Number: " << current << std::endl;
            ++current;
            cv.notify_all();
        }
    }
}

void printOdd()
{
    while (current < MAX)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
                { return current % 2 != 0; });
        if (current <= MAX)
        {
            std::cout << "Odd Number: " << current << std::endl;
            ++current;
            cv.notify_all();
        }
    }
}

int main()
{

    std::thread t(printEven);
    std::thread t_2(printOdd);
    t.join();
    t_2.join();
    return 0;
}
