#include <iostream>
#include <vector>

bool linear_search(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return true;
    }
    return false;
}

bool binary_search(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = arr[mid];

        if (val == target) {
            return true;
        }
        else if (val > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return false;
}

std::vector<int> bubble_sort(std::vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size() - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> arr1 = {5, 3, 8, 1, 2};


    std::cout << std::boolalpha;

    std::cout << linear_search(arr, 31) << std::endl;
    std::cout << binary_search(arr, 3) << std::endl;
    std::vector<int> sorted = bubble_sort(arr1);

    for (int num : sorted) {
        std::cout << num << " ";
    }

    return 0;
}

