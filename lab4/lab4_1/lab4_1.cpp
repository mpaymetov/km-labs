#include "stdafx.h"

constexpr int maxDotCount = 401;
using Matrix = int[maxDotCount][maxDotCount];
using Arr = int[maxDotCount];

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "invalid argument count\n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	int n;
	inputFile >> n;

	if (n > maxDotCount)
	{
		std::cout << "invalid dot count\n";
		return 1;
	}

	Matrix matrix;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			inputFile >> matrix[i][j];

	Arr layer, from;
	int maxStream = 0;
	
	do {
		int lay = 1;

		for (int i = 1; i <= n; ++i)
		{
			layer[i] = 0;
			from[i] = 0;
		}

		for (int j = 1; j <= n; ++j)
			if (matrix[1][j] > 0)
			{
				layer[j] = lay;
				from[j] = 1;
			}

		do
		{
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
				{
					if ((layer[i] == lay) && (matrix[i][j] > 0) && (layer[j] == 0))
					{
						layer[j] = lay + 1;
						from[j] = i;
					}
				}
			++lay;
		} while ((from[n] == 0) && (lay < n));

		std::cout << "lay: " << lay << ";  ";

		if (from[n] == 0)
		{
			break;
		}

		/*for (int i = 1; i <= n; ++i)
			std::cout << i << "->" << layer[i] << "; from: " << from[i] << "\n";*/

		int max = 999;
		int k = n;
		do
		{
			if (max > matrix[from[k]][k])
				max = matrix[from[k]][k];
			k = from[k];
		} while (k != 1);

		std::cout << "max: " << max << std::endl;
		maxStream = maxStream + max;

		k = n;
		do
		{
			matrix[from[k]][k] = matrix[from[k]][k] - max;
			k = from[k];
		} while (k != 1);

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	} while (true);

	std::cout << "maxStream: " << maxStream << std::endl;

	return 0;
}

