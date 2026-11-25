#include <iostream>
#include <exception>

// k is a 0-based index
void removeElement(int*& arr, int& size, int k)
{
	if (k < 0 || k >= size)
	{
		throw std::exception("Invalid index k"); // std::out_of_range
	}

	int* result = new int[size - 1];
	for (int i = 0; i < k; i++)
	{
		result[i] = arr[i];
	}
	for (int i = k + 1; i < size; i++)
	{
		result[i - 1] = arr[i];
	}

	delete[] arr;
	arr = result;
	size--;
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
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int k;
	std::cin >> k;

	try
	{
		removeElement(arr, size, k);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		delete[] arr;
		return 1;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	delete[] arr;

	return 0;
}
