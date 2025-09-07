#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // for std::generate_n

void bubble(std::vector<int>& arr){
    int n =arr.size();
    bool swapped;
    int i;

    for (int i=0; i< n-1; i++){
        swapped = false;
    
        for (int j=0;j < n - i - 1; j++){
            if(arr[j] > arr [j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 10);

    // Create vector with 10,000 random ints
    std::vector<int> v(10);
    std::generate_n(v.begin(), v.size(), [&]() { return dist(gen); });

    // print first 10 to check
    std::cout << "original array ";
    for (int i = 0; i < 10; ++i) std::cout << v[i] << ' ';
    std::cout << '\n';

    bubble(v);
    std::cout<<"sorted array ";
    for (int num : v) std::cout <<num << " ";
    std::cout << "\n";
    return 0;

}