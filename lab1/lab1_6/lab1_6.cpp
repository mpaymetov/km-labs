// lab1_6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

constexpr size_t n = 10;
constexpr size_t maxWeight = 80;

void GetWeightAndCost(std::vector<size_t> w, std::vector<size_t> c, int number, size_t &weight, size_t &cost)
{
	int num = number;
	int bit = 0;
	while (num != 0)
	{
		if (num & 1 == 1)
		{
			weight = weight + w[bit];
			cost = cost + c[bit];
		}
		bit += 1;
		num >>= 1;
	}
}

int main()
{
	std::vector<size_t> w = { 7, 1, 12, 5, 9, 20, 15, 11, 3, 17 };
	std::vector<size_t> c = { 20, 9, 11, 7, 15, 17, 1, 3, 12, 5 };
	size_t weight, cost;
	size_t maxCost = 0;
	int setNum = 0;
	
	for (int i = 0; i < pow(2, n); ++i)
	{
		weight = 0;
		cost = 0;
		GetWeightAndCost(w, c, i, weight, cost);
		if ((weight < maxWeight) && (cost > maxCost))
		{
			maxCost = cost;
			setNum = i;
		}
	}

	std::bitset<n> arrBits(setNum);
	std::cout << "maxCost: " << maxCost << " arrBits: " << arrBits << "\n";

	return 0;
}

