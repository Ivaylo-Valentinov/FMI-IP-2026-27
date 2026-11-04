#include <iostream>

const unsigned int SIZE = 1024;

void sortArray(int arr[], unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        unsigned int index = i;
        for (unsigned int j = i + 1; j < size; j++) {
            if (arr[index] > arr[j]) {
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int binarySearch(const int arr[], unsigned int size, int c) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == c) {
            return middle;
        }

        if (arr[middle] < c) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

void printArray(const int arr[], unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

int main() {
    unsigned int n;
    int arr[SIZE], c;

    std::cin >> n;
    if (n > SIZE) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> c;

    // Task 5
    sortArray(arr, n);
    printArray(arr, n);

    // Task 6
    std::cout << binarySearch(arr, n, c) << std::endl;
    return 0;
}
