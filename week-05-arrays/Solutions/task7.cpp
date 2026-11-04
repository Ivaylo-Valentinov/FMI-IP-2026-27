#include <iostream>

const unsigned int SIZE = 1024;

int main() {
    unsigned int n;
    int array[SIZE];

    std::cin >> n;
    if (n < 3 || n > SIZE) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    // descending sort
    for (unsigned int i = 0; i < n - 1; i++) {
        for (unsigned int j = 0; j < n - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    std::cout << "Largest 3 numbers in the array are: " <<
        array[0] << " " <<
        array[1] << " " <<
        array[2] << std::endl;

    return 0;
}
