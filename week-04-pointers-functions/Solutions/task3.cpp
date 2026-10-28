#include <iostream>

// The result overflows if it does not fit in an int, e.g. my_pow(10, 10)
int my_pow(int a, int b) {
	if (b < 0) {
		return -1;
	}

	int product = 1;
	for (int i = 0; i < b; i++) {
		product *= a;
	}

	return product;
}

void my_other_pow(int* a, int b) {
	*a = my_pow(*a, b);
}

int main() {
	int a, b, c;
	std::cin >> a >> b;

	c = my_pow(a, b);
	std::cout << a << " " << b << " " << c << std::endl;

	my_other_pow(&a, b);
	std::cout << a << " " << b << std::endl;

	return 0;
}
