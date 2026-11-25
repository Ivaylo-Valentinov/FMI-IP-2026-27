#include <iostream>

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

void readMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

int* rowMinimums(int** matrix, int rows, int cols)
{
	int* minimums = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		minimums[i] = matrix[i][0];
		for (int j = 1; j < cols; j++)
		{
			if (matrix[i][j] < minimums[i])
			{
				minimums[i] = matrix[i][j];
			}
		}
	}
	return minimums;
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
	readMatrix(matrix, rows, cols);

	int* minimums = rowMinimums(matrix, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		std::cout << minimums[i] << ' ';
	}
	std::cout << std::endl;

	delete[] minimums;
	deleteMatrix(matrix, rows);

	return 0;
}
