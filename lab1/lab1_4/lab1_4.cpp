// lab1_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

constexpr size_t k = 5;
constexpr size_t n = 25;

void nextCombination(std::vector<size_t> &v, int m)
{
	v[m] += 1;
	if (v[m] > n - k + m)
	{
		if (m > 0)
		{
			nextCombination(v, m - 1);
			v[m] = v[m - 1] + 1;
		}
	}
}

void GenerateReshuffle(const std::vector<size_t> &v)
{
	std::vector<size_t> m(k);
	std::copy(v.begin(), v.end(), m.begin());

	do
	{
		//copy(m.begin(), m.end(), std::ostream_iterator<size_t>(std::cout, " "));
		//std::cout << std::endl;
	} while (std::next_permutation(m.begin(), m.end()));
}

int main()
{
	std::vector<size_t> v;
	for (size_t i = 0; i < k; ++i)
	{
		v.push_back(i);
	}

	boost::timer t;
	t.restart();

	do
	{
		GenerateReshuffle(v); 
		nextCombination(v, k - 1);
	} while (v[0] <= n - k);

	double duration = t.elapsed();
	std::cout << duration << std::endl;
	return 0;
}