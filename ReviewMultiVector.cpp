#include <iostream> 
#include <vector> 
#include <thread> 
#include <mutex> 

std::mutex mtx;
 int global_sum =0 ; 

void partial_sum(std::vector<int> &data,int start,int end) { 

int local_sum = 0; 
for(int i = start ; i < end ; i++) { 
    local_sum+= data[i]; 
}
std::lock_guard<std::mutex> lock(mtx); 
global_sum += local_sum; 

}
int main() {
    std::vector<int> data; 
    std::vector<std::thread> threads; 
    for(int i = 0 ; i <= 100; i++) { 
            data.push_back(i); 
    }
    int num_threads = 5; 
    int chunk_size = data.size() / num_threads; 

    for(int i = 0 ; i < num_threads; i++) { 
        int start = i * chunk_size; 
        int end = (i == num_threads - 1) ? data.size() : (start + chunk_size) ; ;

        threads.push_back(std::thread(partial_sum,std::ref(data),start,end)); 

    }
    for (auto &s : threads)
    {
        /* code */s.join(); 
    }
    std::cout << "Tong cac vector la: " << global_sum << std::endl ; 
    
}