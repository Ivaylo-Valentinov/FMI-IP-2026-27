#include <iostream>

const unsigned int SIZE = 1024;

int main() {
    unsigned int n, m;
    float arr[SIZE];

    std::cin >> n >> m;
    if (n > SIZE) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }
    if (m > n) {
        std::cout << "Invalid m" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (unsigned int i = 0; i < n; i++) {
        unsigned int index = i;
        for (unsigned int j = i + 1; j < n; j++) {
            if (arr[index] > arr[j]) {
                index = j;
            }
        }
        float temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    float minSum = 0;
    float maxSum = 0;

    for (unsigned int i = 0; i < m; i++) {
        minSum += arr[i];
        maxSum += arr[n - m + i];
    }

    std::cout << minSum << std::endl;
    std::cout << maxSum << std::endl;
    return 0;
}
