// lab1_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

constexpr size_t n = 13;

int main()
{
	std::vector<size_t> v;
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(i);
	}
	std::sort(v.begin(), v.end());
	boost::timer t;
	t.restart();
	bool working;

	do
	{
		//copy(v.begin(), v.end(), std::ostream_iterator<size_t>(std::cout, " "));
		//std::cout << std::endl;
		
		working = false;
		size_t m = 0;
		for (size_t i = v.size() - 1; i > 0; --i)
		{
			if (v[i - 1] < v[i]) 
			{
				m = i - 1;
				working = true;
				break;
			}
		}

		if (working) 
		{ 
			size_t k = m + 1;
			size_t min = v[k];
			for (size_t i = m + 1; i < v.size(); ++i)
			{
				if ((v[i] > v[m]) && (v[i] < min))
				{
					k = i;
					min = v[i];
				}
			}

			min = v[m];
			v[m] = v[k];
			v[k] = min;

			std::reverse(v.begin() + m + 1, v.end());
		}
	} while (working);
	
	double duration = t.elapsed();
	std::cout << duration << std::endl;
	return 0;
}