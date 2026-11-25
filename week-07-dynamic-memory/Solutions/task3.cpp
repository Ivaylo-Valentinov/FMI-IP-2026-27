#include <iostream>

int** createMatrix(int size)
{
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	return matrix;
}

void deleteMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

bool isZeroBelowPrimary(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool isZeroAbovePrimary(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool isZeroAboveSecondary(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; i + j < size - 1; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool isZeroBelowSecondary(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - i; j < size; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool isTriangular(int** matrix, int size)
{
	return isZeroBelowPrimary(matrix, size)
		|| isZeroAbovePrimary(matrix, size)
		|| isZeroAboveSecondary(matrix, size)
		|| isZeroBelowSecondary(matrix, size);
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

	int** matrix = createMatrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	if (isTriangular(matrix, size))
	{
		std::cout << "The matrix is triangular" << std::endl;
	}
	else
	{
		std::cout << "The matrix is not triangular" << std::endl;
	}

	deleteMatrix(matrix, size);

	return 0;
}
