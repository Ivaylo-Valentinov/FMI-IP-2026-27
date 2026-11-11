#include <iostream>
using namespace std;

const int MAX_SIZE = 1024;

bool is_valid_k(int array[], int size, int k)
{
	for (int i = k; i < size; i++)
	{
		long long difference = (long long)array[i] - array[i - k];
		if (difference < 0)
		{
			difference = -difference;
		}
		if (difference != k)
		{
			return false;
		}
	}
	return true;
}

int main() {
	int size;
	cin >> size;

	if (size < 1 || size >= MAX_SIZE)
	{
		cout << "Invalid size" << endl;
		return 1;
	}

	int array[MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}

	for (int k = size - 1; k > 0; k--)
	{
		if (is_valid_k(array, size, k))
		{
			cout << k << endl;
			return 0;
		}
	}

	cout << "No solution" << endl;

	return 0;
}
