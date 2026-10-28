#include <iostream>

void print_zigzag(int n) {
	bool left_to_right = true;

	for (int row = 0; row < n; row++) {
		if (left_to_right) {
			for (int col = 1; col <= n; col++) {
				std::cout << row * n + col << " ";
			}
		} else {
			for (int col = n; col >= 1; col--) {
				std::cout << row * n + col << " ";
			}
		}
		std::cout << std::endl;
		left_to_right = !left_to_right;
	}
}

int main() {
	int n;
	std::cin >> n;
	print_zigzag(n);
	return 0;
}
