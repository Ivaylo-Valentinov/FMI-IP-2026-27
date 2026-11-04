#include <iostream>

int sum_digits(int number) {
	if (number < 0) {
		number = -number;
	}

	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

void print_digit_sum_steps(int number) {
	do {
		number = sum_digits(number);
		std::cout << number;
		if (number >= 10) {
			std::cout << " -> ";
		}
	} while (number >= 10);
	std::cout << std::endl;
}

int main() {
	int n;
	std::cin >> n;
	print_digit_sum_steps(n);
	return 0;
}
