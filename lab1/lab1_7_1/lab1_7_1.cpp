// lab1_7_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

constexpr size_t n = 6;
constexpr size_t a[n][n] = {
	{ 0, 5, 0, 0, 0, 7 },
	{ 5, 0, 14, 8, 0, 0 },
	{ 0, 14, 0, 3, 5, 0 },
	{ 0, 8, 3, 0, 2, 0 },
	{ 0, 0, 5, 2, 0, 6 },
	{ 7, 0, 0, 0, 6, 0 }
};

size_t Hamilton(const std::vector<size_t> &v)
{
	size_t sum = 0;
	for (size_t i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		if (a[v[i]][v[j]] == 0)
		{
			return 0;
		}
		else
		{
			sum = sum + a[v[i]][v[j]];
		}
	}
	return sum;
}

int main()
{	
	std::vector<size_t> v, w;
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
	}

	size_t minLength = std::numeric_limits<std::size_t>::max();

	do
	{
		size_t pathLength = Hamilton(v);
		if ((pathLength != 0) && (pathLength < minLength))
		{
			minLength = pathLength;
			w.clear();
			for (int i = 0; i < n; ++i)
			{
				w.push_back(v[i]);
			}
		}
	} while (std::next_permutation(v.begin(), v.end()));

	std::cout << "minLength: " << minLength << "\n";
	std::copy(w.begin(), w.end(), std::ostream_iterator<size_t>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}

