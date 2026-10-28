#include <iostream>

int count_digits(int number) {
	if (number == 0) {
		return 1;
	}
	if (number < 0) {
		number = -number;
	}

	int count = 0;
	while (number > 0) {
		number /= 10;
		count++;
	}
	return count;
}


int count_occurrences(int number, int digit) {
	if (number == 0) {
		return digit == 0 ? 1 : 0;
	}
	if (number < 0) {
		number = -number;
	}

	int count = 0;
	while (number > 0) {
		if (digit == number % 10) {
			count++;
		}
		number /= 10;
	}
	return count;
}

void print_sorted_digits(int number) {
	for (int i = 0; i < 10; i++) {
		int digit_count = count_occurrences(number, i);
		for (int j = 0; j < digit_count; j++) {
			std::cout << i;
		}
	}
	std::cout << std::endl;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << count_digits(a) << std::endl << count_occurrences(a, b) << std::endl;
	print_sorted_digits(a);
	return 0;
}
