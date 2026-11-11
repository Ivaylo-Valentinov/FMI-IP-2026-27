#include <iostream>
using namespace std;

int digits_sum(long long number)
{
	if (number < 0)
	{
		number = -number;
	}

	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

bool is_funny(int number)
{
	int last_digit = number % 10;
	number /= 10;
	while (number > 0)
	{
		int digit = number % 10;
		if (digit % 2 == last_digit % 2)
		{
			return false;
		}
		last_digit = digit;
		number /= 10;
	}
	return true;
}

int main() {
	long long a, b;
	cin >> a >> b;

	long long total = 0;
	for (long long i = a; i <= b; i++)
	{
		if (is_funny(digits_sum(i)))
		{
			total += i;
		}
	}

	cout << total << endl;

	return 0;
}
