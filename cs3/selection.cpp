#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::generate_n

void selection(std::vector<int>&arr){
    int n = arr.size();
    for ( int i=0; i< n-1; i++){
        int min_idx = i;
        for (int j = i+1; j<n; j++){
            if (arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        std::swap (arr [i], arr[min_idx]);
    }
}
void printArray(std::vector<int>&arr){
    for (int &val : arr){
        std::cout << val << " ";
    }
}


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    // this changes the values in the array.
    std::uniform_int_distribution<> dist(0, 10);
    // Create vector with 10,000 random ints atm its just 10 cuz easier.
    std::vector<int> arr(10);
    std::generate_n(arr.begin(), arr.size(), [&]() { return dist(gen); });
    std::cout << "Before sort ";
    // print first 10 to check
    for (int i = 0; i < 10; ++i) std::cout << arr[i] << ' ';
    std::cout << '\n';

    std::cout<< "sorted array ";
    selection(arr);
    printArray(arr);
    return 0;
}