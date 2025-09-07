#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::generate_n
#include <chrono>// for time complexity


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100000);

    // Create vector with 10,000 random ints
    std::vector<int> arr(10000);
    std::generate_n(arr.begin(), arr.size(), [&]() { return dist(gen); });

    // print first 10 to check
    for (int i = 0; i < 10; ++i) std::cout << arr[i] << ' ';
    std::cout << '\n';
    int i;
    std::cout<< arr[i] <<" ";
        // Record the start time
        auto start = std::chrono::high_resolution_clock::now();
        // Code block to measure
        for (int i = 0; i < 1000000; ++i) {
            // Simulating some work
        }
        // Record the end time
        auto end = std::chrono::high_resolution_clock::now();
    
        // Calculate the duration
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout<< '\n';
        std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;    
    return 0;
}
