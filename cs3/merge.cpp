#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::generate_n
#include <chrono>



void merge(std::vector<int>&arr,int left ,int mid,int right){

    //finds two subarrays
    int n1 = mid -left +1;
    int n2 = right - mid;
    //create temp arrays
    std::vector<int> L(n1), R(n2);

    //copies data between vectors
    for (int i=0; i< n1; i++){
        L[i] = arr[left+i];}
    for (int j=0; j< n2; j++){
        R[j] = arr[mid +1 +j];
    }
    int i=0,j=0;
    int k =left;
    while (i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
    else {
        arr[k] = R[j];
        j++;
        }    
        k++;
    }
    while ( i <n1){
        arr[k]= L[i];
        i++;
        k++;
    }
}
void mergesort(std::vector<int>&arr, int left, int right){
    if (left>=right)
       return;
    
    int mid =left +(right-left) /2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);

}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    // this changes the values in the array.
    std::uniform_int_distribution<> dist(0, 10000);
    // Create vector with 10,000 random ints atm its just 10 cuz easier.
    std::vector<int> arr(10000);
    //generates the array
    std::generate_n(arr.begin(), arr.size(), [&]() { return dist(gen); });
    std::cout << "Before sort ";
    // print first 10 to check
    for (int i = 0; i < 10; ++i) std::cout << arr[i] << ' ';
    std::cout << '\n';
    int n = arr.size();
    std::cout<< "sorted array ";
    mergesort(arr,0,n-1);
    for (int i = 0; i<arr.size(); i++)

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
