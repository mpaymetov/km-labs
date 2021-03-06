#include "stdafx.h"

constexpr int maxDotCount = 401;

using Matrix = int[maxDotCount][maxDotCount];
using Color = int[maxDotCount];

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

	Color color;
	for (int i = 1; i <= n; ++i)
		color[i] = 0;

	bool working;
	int c = 0;
	std::vector<int> a;

	for (int k = 1; k <= n; ++k)
		if (color[k] == 0)
		{
			++c;
			color[k] = c;
			working = true;
			do
			{
				a.clear();
				for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= n; ++j)
					{
						if ((matrix[k][i] == 1) && (matrix[i][j] == 1) && (j != k) && (color[j] == 0) && (matrix[k][j] == 0))
							a.push_back(j);
					}
				}

				if (a.empty())
				{
					working = false;
				}
				else
				{
					std::sort(a.begin(), a.end());
					color[a[0]] = c;
					for (int i = 1; i <= n; ++i)
					{
						if (matrix[a[0]][i] > 0) matrix[k][i] = matrix[a[0]][i];
						matrix[a[0]][i] = 0;
						if (matrix[i][a[0]] > 0) matrix[i][k] = matrix[i][a[0]];
						matrix[i][a[0]] = 0;
					}
				}
			} while (working);
		}

	std::cout << c << std::endl;
	for (int i = 1; i <= n; ++i)
		std::cout << i << " " << color[i] << std::endl;

    return 0;
}
