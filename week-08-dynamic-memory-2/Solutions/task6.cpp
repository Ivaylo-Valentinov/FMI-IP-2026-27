#include <iostream>
#include <exception>

void readArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printArray(const int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void rotateRight(int* arr, int size, int k)
{
	if (k < 0)
	{
		throw std::exception("k must be non-negative"); // std::invalid_argument
	}

	// rotating by size steps returns the original array
	k %= size;

	int* rotated = new int[size];
	for (int i = 0; i < size; i++)
	{
		rotated[(i + k) % size] = arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = rotated[i];
	}

	delete[] rotated;
}

int main()
{
	int size;
	std::cin >> size;

	if (size < 1)
	{
		std::cout << "Invalid size" << std::endl;
		return 1;
	}

	int* arr = new int[size];
	readArray(arr, size);

	int k;
	std::cin >> k;

	try
	{
		rotateRight(arr, size, k);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		delete[] arr;
		return 1;
	}

	printArray(arr, size);
	delete[] arr;

	return 0;
}
