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
void removeColumn(int** matrix, int rows, int& cols, int k)
{
	if (k < 0 || k >= cols)
	{
		throw std::exception("Invalid column index k"); // std::out_of_range
	}

	for (int i = 0; i < rows; i++)
	{
		int* newRow = new int[cols - 1];
		for (int j = 0; j < k; j++)
		{
			newRow[j] = matrix[i][j];
		}
		for (int j = k + 1; j < cols; j++)
		{
			newRow[j - 1] = matrix[i][j];
		}

		delete[] matrix[i];
		matrix[i] = newRow;
	}

	cols--;
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
		removeColumn(matrix, rows, cols, k);
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
