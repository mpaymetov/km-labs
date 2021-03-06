// lab1_5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

constexpr size_t n = 10;

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, n - 1);

	std::vector<size_t> v;
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(i);
	}

	for (size_t i = 0; i < n; ++i)
	{
		size_t j = dist(gen);
		size_t k = v[i];
		v[i] = v[j];
		v[j] = k;
	}
	
	for (size_t i = 0; i < n; ++i)
	{
		std::cout << v[i] << " ";
	}

	std::cout << "\n";
    return 0;
}
