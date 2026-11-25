#include <iostream>
#include <exception>

void printNumber(const int* number)
{
	if (number == nullptr)
	{
		throw std::exception("Received nullptr"); // std::invalid_argument
	}

	std::cout << *number << std::endl;
}

int main()
{
	int x = 42;
	int* validPtr = &x;
	int* nullPtr = nullptr;

	try
	{
		printNumber(validPtr);
		printNumber(nullPtr);
		std::cout << "This line is never reached" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error while executing printNumber: " << e.what() << std::endl;
	}

	return 0;
}
