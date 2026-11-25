#include <iostream>
#include <exception>

int* readArray(int& size)
{
	std::cin >> size;
	if (size < 1)
	{
		throw std::exception("Invalid size"); // std::invalid_argument
	}

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	return arr;
}

void printArray(const int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

bool contains(const int* arr, int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
	return false;
}

void addIfMissing(int* arr, int& size, int value)
{
	if (!contains(arr, size, value))
	{
		arr[size] = value;
		size++;
	}
}

void shrinkArray(int*& arr, int newSize)
{
	int* result = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{
		result[i] = arr[i];
	}

	delete[] arr;
	arr = result;
}

int* intersection(const int* arr1, int size1, const int* arr2, int size2, int& resultSize)
{
	// the intersection can't have more elements than arr1
	int* result = new int[size1];
	resultSize = 0;

	for (int i = 0; i < size1; i++)
	{
		if (contains(arr2, size2, arr1[i]))
		{
			addIfMissing(result, resultSize, arr1[i]);
		}
	}

	shrinkArray(result, resultSize);
	return result;
}

int* unite(const int* arr1, int size1, const int* arr2, int size2, int& resultSize)
{
	// the union can't have more elements than both arrays together
	int* result = new int[size1 + size2];
	resultSize = 0;

	for (int i = 0; i < size1; i++)
	{
		addIfMissing(result, resultSize, arr1[i]);
	}
	for (int i = 0; i < size2; i++)
	{
		addIfMissing(result, resultSize, arr2[i]);
	}

	shrinkArray(result, resultSize);
	return result;
}

// returns the 0-based indices in arr1 of the elements that are not in arr2
int* differenceIndices(const int* arr1, int size1, const int* arr2, int size2, int& resultSize)
{
	int* indices = new int[size1];
	resultSize = 0;

	for (int i = 0; i < size1; i++)
	{
		if (!contains(arr2, size2, arr1[i]))
		{
			indices[resultSize] = i;
			resultSize++;
		}
	}

	shrinkArray(indices, resultSize);
	return indices;
}

// the indices are printed 1-based
void printDifference(const int* arr, const int* indices, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[indices[i]] << ' ';
	}
	std::cout << std::endl;

	std::cout << "Indices: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << indices[i] + 1 << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int size1, size2;
	int* arr1 = nullptr;
	int* arr2 = nullptr;

	try
	{
		arr1 = readArray(size1);
		arr2 = readArray(size2);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		delete[] arr1;
		return 1;
	}

	int resultSize;

	int* result = intersection(arr1, size1, arr2, size2, resultSize);
	std::cout << "Intersection: ";
	printArray(result, resultSize);
	delete[] result;

	result = unite(arr1, size1, arr2, size2, resultSize);
	std::cout << "Union: ";
	printArray(result, resultSize);
	delete[] result;

	result = differenceIndices(arr1, size1, arr2, size2, resultSize);
	std::cout << "Difference: ";
	printDifference(arr1, result, resultSize);
	delete[] result;

	delete[] arr2;
	delete[] arr1;

	return 0;
}
