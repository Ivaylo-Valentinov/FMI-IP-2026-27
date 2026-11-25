#include <iostream>
#include <exception>

int** createMatrix(int rows, int cols)
{
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
}

void deleteMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

// k is a 0-based index
void removeRow(int**& matrix, int& rows, int k)
{
	if (k < 0 || k >= rows)
	{
		throw std::exception("Invalid row index k"); // std::out_of_range
	}

	int** result = new int*[rows - 1];
	for (int i = 0; i < k; i++)
	{
		result[i] = matrix[i];
	}
	for (int i = k + 1; i < rows; i++)
	{
		result[i - 1] = matrix[i];
	}

	// the other rows are reused by result, so only row k and the old array of pointers are freed
	delete[] matrix[k];
	delete[] matrix;
	matrix = result;
	rows--;
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	if (rows < 1 || cols < 1)
	{
		std::cout << "Invalid size" << std::endl;
		return 1;
	}

	int** matrix = createMatrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	int k;
	std::cin >> k;

	try
	{
		removeRow(matrix, rows, k);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		deleteMatrix(matrix, rows);
		return 1;
	}

	printMatrix(matrix, rows, cols);
	deleteMatrix(matrix, rows);

	return 0;
}
