#include <iostream>

const unsigned int SIZE = 1024;

int main() {
    int arr[SIZE];

    unsigned int n;
    std::cin >> n;
    if (n == 0 || n > SIZE) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    unsigned int maxLen = 0;
    int maxLenNum = arr[0];
    unsigned int i = 0;

    while (i < n) {
        unsigned int j = i + 1, currLen = 1;
        while (j < n && arr[j] == arr[i]) {
            currLen++;
            j++;
        }
        if (currLen > maxLen) {
            maxLen = currLen;
            maxLenNum = arr[i];
        }
        i = j;
    }

    std::cout << maxLenNum << " " << maxLen;
    return 0;
}
