#include "stdafx.h"

constexpr int maxDotCount = 100;
using Matrix = int[maxDotCount + 1][maxDotCount + 1];

bool kuhn(int &i, int &p, int &q, Matrix &m, std::vector<int> &a, std::vector<int> &b)
{
	for (int j = 1; j <= q; ++j)
		if ((m[i][j] == 1) && (a[i] != j) )
		{
			if (b[j] == 0)
			{
				a[i] = j;
				b[j] = i;
				return true;
			}
			else if (kuhn(b[j], p, q, m, a, b))
			{
				a[i] = j;
				b[j] = i;
				return true;
			}
		}
	return false;
};

bool isMatchFull(std::vector<int> & a, int &p)
{
	for (int i = 1; i <= p; ++i)
		if (a[i] == 0)
			return false;
	return true;
}

void PrintMatch(std::vector<int> & a, int &p)
{
	for (int i = 1; i <= p; ++i)
		if (a[i] != 0)
			std::cout << i << " " << a[i] << "\n";
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "invalid argument count\n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	int p, q;
	Matrix matrix;
	std::vector<int> a(maxDotCount + 1, 0), b(maxDotCount + 1, 0);

	inputFile >> p >> q;
	if ((p > maxDotCount) || (q > maxDotCount))
	{
		std::cout << "invalid dot count\n";
		return 1;
	}

	for (int i = 1; i <= p; ++i)
		for (int j = 1; j <= q; ++j)
			inputFile >> matrix[i][j];

	for (int i = 1; i <= p; ++i)
		kuhn(i, p, q, matrix, a, b);

	std::cout << ((isMatchFull(a, p)) ? "YES" : "NO") << "\n";
	PrintMatch(a, p);

    return 0;
}

