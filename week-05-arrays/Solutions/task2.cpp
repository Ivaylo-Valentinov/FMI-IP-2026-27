#include <iostream>

const unsigned int SIZE = 1024;
const unsigned int MAX_DIGITS = 10;

bool isPalindrome(const int arr[], unsigned int n) {
    for (unsigned int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            return false;
        }
    }

    return true;
}

bool isPalindrome(unsigned int number) {
    int digits[MAX_DIGITS];
    unsigned int len = 0;

    do {
        digits[len++] = number % 10;
        number /= 10;
    } while (number > 0);

    return isPalindrome(digits, len);
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

    std::cout << isPalindrome(arr, n) << std::endl;

    unsigned int number;
    std::cin >> number;

    std::cout << isPalindrome(number) << std::endl;
    return 0;
}
