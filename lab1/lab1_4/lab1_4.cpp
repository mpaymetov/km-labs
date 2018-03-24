// lab1_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

constexpr size_t k = 5;
constexpr size_t n = 10;

int CalcBits(const int number)
{
	int num = number;
	int bits = 0;
	while (num != 0)
	{
		bits += num & 1;
		num >>= 1;
	}
	return bits;
}

void PrintVector(std::vector<size_t> v, int number)
{
	int num = number;
	int bit = 0;
	std::vector<size_t> m;
	while (num != 0)
	{
		if (num & 1 == 1)
		{
			m.push_back(v[bit]);
		}
		bit += 1;
		num >>= 1;
	}

	std::sort(m.begin(), m.end());
	do
	{
		copy(m.begin(), m.end(), std::ostream_iterator<size_t>(std::cout, " "));
		std::cout << std::endl;
	} while (std::next_permutation(m.begin(), m.end()));

	//std::cout << "\n";
}

int main()
{
	std::vector<size_t> v;
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(i);
	}

	boost::timer t;
	t.restart();

	for (int i = 0; i < pow(2, n); ++i)
	{
		if (CalcBits(i) == k)
		{
			//std::bitset<n> num(i);
			//std::cout << num << "\n";
			PrintVector(v, i);
		}
	}

	double duration = t.elapsed();
	std::cout << duration << std::endl;
	return 0;
}