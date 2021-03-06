// lab1_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

constexpr int n = 10;

void swap(int *arr, int i, int j)
{
	int s = arr[i];
	arr[i] = arr[j];
	arr[j] = s;
}

void PrintReshuffle(int *a)
{
	for (int i = 1; i < n + 1; ++i)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
}

int main()
{
	int reshuffle[n + 2];
	int invert[n + 2];
	int d[n + 2];
	int m = n;
	
	for (int i=0; i < n+2; ++i)
	{
		reshuffle[i] = i;
		invert[i] = i;
		d[i] = -1;
	}

	boost::timer t;
	t.restart(); 
	
	d[1] = 0;
	reshuffle[0] = m + 1;
	reshuffle[n + 1] = m + 1;

	while (m != 1)
	{
		//PrintReshuffle(reshuffle);
		m = n;
		while (reshuffle[invert[m] + d[m]] > m)
		{
			d[m] = -1 * d[m];
			m -= 1;
		}
		swap(reshuffle, invert[m], invert[m] + d[m]);
		swap(invert, reshuffle[invert[m]], m);
	}
	
	double duration = t.elapsed();
	std::cout << duration << std::endl;

    return 0;
}

