#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::generate_n
#include <chrono>// for time complexity

void insertion(std::vector<int>&arr){
    int n = arr.size();
    for (int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
static void printarray(std::vector<int>&arr){
    int n =arr.size();
    for( int i = 0; i < n;i++)
        std::cout<<arr[i] << " ";
    std::cout << "\n";

}

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

    int n = arr.size();
    auto start = std::chrono::high_resolution_clock::now();

    insertion(arr);
    auto end = std::chrono::high_resolution_clock::now();
    //printarray(arr);
    int i;

    std::cout<< arr[i] <<" ";
        // Record the start time

        // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout<< '\n';
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;    
    return 0;
}
