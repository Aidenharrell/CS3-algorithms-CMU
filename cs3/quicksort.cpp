#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::generate_n
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
    std::uniform_int_distribution<> dist(0, 10);

    // Create vector with random ints
    std::vector<int> v(10);
    std::generate_n(v.begin(), v.size(), [&]() { return dist(gen); });
    std::cout<<" Before quicksort ";
    // print first 10 to check
    for (int i = 0; i < 10; ++i) std::cout << v[i] << ' ';
    std::cout << '\n';
    quicksort(v, 0, v.size()-1);
    std::cout<<" after quicksort ";

    for (int i=0; i<10; i++){
    std::cout<< v[i] <<' ' ;
    }
    std::cout << '\n';
    return 0;
}
