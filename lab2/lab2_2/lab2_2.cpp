// lab2_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


constexpr int maxDotCount = 401;

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "invalid argument count\n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	int dotCount;
	inputFile >> dotCount;

	std::cout << "dotCount: " << dotCount << "\n";

	int matrix[maxDotCount][maxDotCount];

	for (int i = 0; i < maxDotCount; ++i)
		for (int j = 0; j < maxDotCount; ++j)
			matrix[i][j] = 0;

	for (int i = 1; i <= dotCount; ++i)
		for (int j = 1; j <= dotCount; ++j)
	{
			inputFile >> matrix[i][j];
	}

	for (int i = 1; i <= dotCount; ++i)
	{
		for (int j = 1; j <= dotCount; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}

    return 0;
}

