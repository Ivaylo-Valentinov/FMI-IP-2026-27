#include <iostream>

const unsigned int SIZE = 1024;

bool hasProperty1(const int arr[], unsigned int size) {
    if (size == 0) {
        return true;
    }

    bool isEven, prevIsEven;
    isEven = arr[0] % 2 == 0;
    for (unsigned int i = 1; i < size; i++) {
        prevIsEven = isEven;
        isEven = arr[i] % 2 == 0;
        if (prevIsEven == isEven) {
            return false;
        }
    }

    return true;
}

bool hasProperty2(const int arr[], unsigned int size) {
    for (unsigned int i = 2; i + 1 < size; i += 2) {
        if (arr[i] != arr[i - 1] + arr[i + 1]) {
            return false;
        }
    }

    return true;
}

unsigned int countDigits(unsigned int number) {
    if (number == 0) {
        return 1;
    }

    unsigned int count = 0;
    while (number > 0) {
        count++;
        number /= 10;
    }

    return count;
}

bool containsNumber(int number, unsigned int index) {
    if (number == 0 && index == 0) {
        return true;
    }

    unsigned int absNumber = number >= 0 ? number : -number;

    unsigned int digitCount = countDigits(index);
    unsigned int residue = 1;

    for (unsigned int i = 0; i < digitCount; i++) {
        residue *= 10;
    }

    while (absNumber > 0) {
        if (absNumber % residue == index) {
            return true;
        }

        absNumber /= 10;
    }

    return false;
}

bool hasProperty3(const int arr[], unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (!containsNumber(arr[i], i)) {
            return false;
        }
    }

    return true;
}

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

    if (hasProperty1(arr, n)) {
        std::cout << "Has property 1!\n";
    }

    if (hasProperty2(arr, n)) {
        std::cout << "Has property 2!\n";
    }

    if (hasProperty3(arr, n)) {
        std::cout << "Has property 3!\n";
    }

    return 0;
}
