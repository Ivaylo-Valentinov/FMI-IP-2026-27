#include <iostream>

bool is_palindrome(int number) {
	if (number < 0) {
		number = -number;
	}

	int original = number;
	// long long, because the reversed number may not fit in an int, e.g. 1999999999
	long long reversed = 0;
	while (number > 0) {
		reversed = reversed * 10 + number % 10;
		number /= 10;
	}
	return original == reversed;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << std::boolalpha << is_palindrome(n) << std::endl;
	return 0;
}
