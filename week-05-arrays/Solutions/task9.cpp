#include <iostream>

const unsigned int SIZE = 1024;
const unsigned int LETTERS = 26;

int main() {
    unsigned int n;
    std::cin >> n;
    if (n > SIZE) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }

    char arr[SIZE];
    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if (arr[i] < 'a' || arr[i] > 'z') {
            std::cout << "Invalid letter" << std::endl;
            return 1;
        }
    }

    unsigned int counts[LETTERS] = { 0 };

    for (unsigned int i = 0; i < n; i++) {
        counts[arr[i] - 'a']++;
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cout << counts[arr[i] - 'a'] << " ";
    }

    return 0;
}
