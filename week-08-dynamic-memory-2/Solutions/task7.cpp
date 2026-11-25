#include <iostream>

// returns -1 if value is not in arr
int indexOf(const char* arr, int size, char value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int countDistinct(const char* symbols, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (indexOf(symbols, i, symbols[i]) == -1)
		{
			count++;
		}
	}
	return count;
}

void buildHistogram(const char* symbols, int size, char*& histogramSymbols, int*& histogramCounts, int& histogramSize)
{
	int distinct = countDistinct(symbols, size);
	histogramSymbols = new char[distinct];
	histogramCounts = new int[distinct];
	histogramSize = 0;

	for (int i = 0; i < size; i++)
	{
		int index = indexOf(histogramSymbols, histogramSize, symbols[i]);
		if (index == -1)
		{
			histogramSymbols[histogramSize] = symbols[i];
			histogramCounts[histogramSize] = 1;
			histogramSize++;
		}
		else
		{
			histogramCounts[index]++;
		}
	}
}

void printHistogram(const char* histogramSymbols, const int* histogramCounts, int histogramSize)
{
	for (int i = 0; i < histogramSize; i++)
	{
		std::cout << histogramSymbols[i] << ' ' << histogramCounts[i] << std::endl;
	}
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

	char* symbols = new char[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> symbols[i];
	}

	char* histogramSymbols;
	int* histogramCounts;
	int histogramSize;
	buildHistogram(symbols, size, histogramSymbols, histogramCounts, histogramSize);
	printHistogram(histogramSymbols, histogramCounts, histogramSize);

	delete[] histogramCounts;
	delete[] histogramSymbols;
	delete[] symbols;

	return 0;
}
