#include <iostream>

const unsigned int SIZE = 100;

int sumMatrix(const int matrix[][SIZE], unsigned int rows, unsigned int cols) {
    int sum = 0;
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int minElement(const int matrix[][SIZE], unsigned int rows, unsigned int cols) {
    int min = matrix[0][0];
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }

    return min;
}

int maxElement(const int matrix[][SIZE], unsigned int rows, unsigned int cols) {
    int max = matrix[0][0];
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    return max;
}

int main() {
    unsigned int n, m;
    int matrix[SIZE][SIZE];

    std::cin >> n >> m;
    if (n == 0 || n > SIZE) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }
    if (m == 0 || m > SIZE) {
        std::cout << "Invalid m" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Sum: " << sumMatrix(matrix, n, m) << std::endl;

    // Additional task
    std::cout << "Min: " << minElement(matrix, n, m) << std::endl;
    std::cout << "Max: " << maxElement(matrix, n, m) << std::endl;
    return 0;
}
