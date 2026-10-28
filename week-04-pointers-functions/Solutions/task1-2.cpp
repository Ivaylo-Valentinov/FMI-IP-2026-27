#include <iostream>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// Overflows for INT_MIN, because -INT_MIN does not fit in an int
int absolute_value(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int a, b, c;
	std::cin >> a >> b;

	swap(&a, &b);
	std::cout << a << " " << b << std::endl;

	swap(a, b);
	std::cout << a << " " << b << std::endl;

	c = absolute_value(a);
	std::cout << c << std::endl;
	return 0;
}
