#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::generate_n
#include <chrono>
// partion to split in half or in different parts everytime.
int partition(std::vector<int>&arr, int low, int high){
    //chooses pivot
    int pivot = arr[high];
    //right or farthest pivot
    int i = low - 1;

    for (int j = low; j<= high -1; j++){
        if (arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);

    return i + 1;
}

void quicksort(std::vector<int>&arr, int low, int high){
    if (low < high){
        int pi =partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100000);

    // Create vector with random ints
    std::vector<int> arr(10000);
    std::generate_n(arr.begin(), arr.size(), [&]() { return dist(gen); });
    std::cout<<" Before quicksort ";
    // print first 10 to check or change for full set
    //for (int i = 0; i < arr.size(); ++i) std::cout << arr[i] << ' ';
    //std::cout << '\n';

    auto start = std::chrono::high_resolution_clock::now();
    quicksort(arr, 0, arr.size()-1);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<<" after quicksort ";

//for print out of array after
    //for (int i=0; i<arr.size(); i++){
    //std::cout<< arr[i] <<' ' ;}

    std::cout << '\n';

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout<< '\n';
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}