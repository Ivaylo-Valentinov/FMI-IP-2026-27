#include <iostream>

const unsigned int SIZE = 1024;

int main() {
    int arr[SIZE];

    unsigned int n;
    std::cin >> n;
    if (n > SIZE) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (unsigned int i = n; i > 0; i--) {
        if (arr[i - 1] < 0) {
            for (unsigned int j = i - 1; j + 1 < n; j++) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
