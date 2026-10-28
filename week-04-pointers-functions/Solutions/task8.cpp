#include <iostream>

int last_two_digits_difference(unsigned int number) {
	int last = number % 10;
	int second_to_last = number / 10 % 10;

	if (last > second_to_last) {
		return last - second_to_last;
	}
	return second_to_last - last;
}

int max_adjacent_difference(unsigned int number) {
	int max_difference = 0;

	while (number >= 10) {
		int difference = last_two_digits_difference(number);
		if (difference > max_difference) {
			max_difference = difference;
		}
		number /= 10;
	}
	return max_difference;
}

int main() {
	unsigned int n;
	std::cin >> n;
	std::cout << max_adjacent_difference(n) << std::endl;
	return 0;
}
