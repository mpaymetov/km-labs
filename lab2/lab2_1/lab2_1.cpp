// lab2_1.cpp: определяет точку входа для консольного приложения.
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

	int dotCount, lineCount;
	inputFile >> dotCount >> lineCount;
	
	std::cout << "dotCount: " << dotCount << "; lineCount: " << lineCount << "\n";

	int matrix[maxDotCount][maxDotCount];

	for (int i = 0; i < maxDotCount; ++i)
		for (int j = 0; j < maxDotCount; ++j)
			matrix[i][j] = 0;

	for (int i = 1; i <= lineCount; ++i)
	{
		int a, b;
		inputFile >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	for (int i = 1; i <= dotCount; ++i)
	{
		for (int j = 1; j <= dotCount; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}

	int color[maxDotCount], stek[maxDotCount], forw[maxDotCount], backw[maxDotCount];
	for (int i = 0; i < maxDotCount; ++i) 
	{
		color[i] = 0;
		stek[i] = 0;
		forw[i] = 0;
		backw[i] = 0;
	}
	
	int k = 1;
	color[k] = 1;

	bool working;
	int iter = 1;
	forw[k] = iter;
	int headStek = 0;

	do
	{
		std::cout << k << " ";

		++iter;
		working = false;
		for (int i = 1; i <= dotCount; ++i)
		{
			if ((matrix[k][i] != 0) && (color[i] == 0))
			{
				color[k] = 2;
				++headStek;
				stek[headStek] = k;
				k = i;
				color[k] = 1;
				forw[k] = iter;
				working = true;
				break;
			}
		}

		if (!working)
		{
			if (headStek != 0)
			{
				color[k] = 2;
				backw[k] = iter;
				k = stek[headStek];
				--headStek;
				working = true;
			}
		}
	} while (working);
	backw[k] = iter;
	std::cout << "\n" << "iter: " << iter << "\n";

	for (int i = 1; i <= dotCount; ++i)
	{
		std::cout << color[i] << " ";
	}
	std::cout << "\n";

	for (int i = 1; i <= dotCount; ++i)
	{
		std::cout << forw[i] << " ";
	}
	std::cout << "\n";

	for (int i = 1; i <= dotCount; ++i)
	{
		std::cout << backw[i] << " ";
	}
	std::cout << "\n";

	return 0;
}

