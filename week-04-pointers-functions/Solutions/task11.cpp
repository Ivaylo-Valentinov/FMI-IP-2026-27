#include <iostream>

bool is_prime(size_t number) {
	if (number <= 1) {
		return false;
	}

	// If number has a divisor greater than its square root, it also has one smaller than it,
	// so it is enough to check up to the square root
	for (size_t i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			return false;
		}
	}

	return true;
}

void print_pairs(size_t number) {
	// A slower solution that tries every pair (i, j):
	// for (size_t i = 1; i < number; i++) {
	// 	for (size_t j = i; j < number; j++) {
	// 		if (is_prime(i) && is_prime(j) && i + j == number) {
	// 			std::cout << "<" << i << ", " << j << ">\n";
	// 		}
	// 	}
	// }

	// b = number - a is determined by a, so a single loop is enough.
	// Stopping at number / 2 keeps a <= b, so each pair is printed only once.
	for (size_t a = 2; a <= number / 2; a++) {
		size_t b = number - a;
		if (is_prime(a) && is_prime(b)) {
			std::cout << "<" << a << ", " << b << ">\n";
		}
	}
}

int main() {
	size_t n;
	std::cin >> n;
	print_pairs(n);
	return 0;
}
