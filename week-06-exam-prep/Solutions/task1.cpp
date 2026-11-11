#include <iostream>

const int MAX_SIZE = 100;

// colStep = 1 is parallel to the primary diagonal, colStep = -1 to the secondary one
void printDiagonal(int matrix[][MAX_SIZE], int size, int row, int col, int colStep)
{
	std::cout << matrix[row][col];
	row++;
	col += colStep;

	while (row < size && col >= 0 && col < size)
	{
		std::cout << ' ' << matrix[row][col];
		row++;
		col += colStep;
	}
	std::cout << std::endl;
}

void printDiagonals(int matrix[][MAX_SIZE], int size)
{
	std::cout << "Главен диагонал:" << std::endl;
	printDiagonal(matrix, size, 0, 0, 1);

	std::cout << "Останалите диагонали в тази посока:" << std::endl;
	for (int col = 1; col < size; col++)
	{
		printDiagonal(matrix, size, 0, col, 1);
	}
	for (int row = 1; row < size; row++)
	{
		printDiagonal(matrix, size, row, 0, 1);
	}

	std::cout << "Второстепенен диагонал:" << std::endl;
	printDiagonal(matrix, size, 0, size - 1, -1);

	std::cout << "Останалите диагонали в тази посока:" << std::endl;
	for (int col = size - 2; col >= 0; col--)
	{
		printDiagonal(matrix, size, 0, col, -1);
	}
	for (int row = 1; row < size; row++)
	{
		printDiagonal(matrix, size, row, size - 1, -1);
	}
}

void printDiagonalsWithLoops(int matrix[][MAX_SIZE], int size)
{
	std::cout << "Главен диагонал:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i > 0) std::cout << ' ';
		std::cout << matrix[i][i];
	}
	std::cout << std::endl;

	std::cout << "Останалите диагонали в тази посока:" << std::endl;
	// above the primary diagonal
	for (int d = 1; d < size; d++)
	{
		for (int j = 0; d + j < size; j++)
		{
			if (j > 0) std::cout << ' ';
			std::cout << matrix[j][d + j];
		}
		std::cout << std::endl;
	}
	// below the primary diagonal
	for (int d = 1; d < size; d++)
	{
		for (int j = 0; d + j < size; j++)
		{
			if (j > 0) std::cout << ' ';
			std::cout << matrix[d + j][j];
		}
		std::cout << std::endl;
	}

	std::cout << "Второстепенен диагонал:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i > 0) std::cout << ' ';
		std::cout << matrix[i][size - 1 - i];
	}
	std::cout << std::endl;

	std::cout << "Останалите диагонали в тази посока:" << std::endl;
	// above the secondary diagonal
	for (int d = size - 2; d >= 0; d--)
	{
		for (int j = 0; j <= d; j++)
		{
			if (j > 0) std::cout << ' ';
			std::cout << matrix[j][d - j];
		}
		std::cout << std::endl;
	}
	// below the secondary diagonal
	for (int d = 1; d < size; d++)
	{
		for (int j = 0; d + j < size; j++)
		{
			if (j > 0) std::cout << ' ';
			std::cout << matrix[d + j][size - 1 - j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	int size;
	std::cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		std::cout << "Invalid size" << std::endl;
		return 1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	printDiagonals(matrix, size);
	// printDiagonalsWithLoops(matrix, size);

	return 0;
}
