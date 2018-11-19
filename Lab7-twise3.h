// Lab7-twise3.cpp
// Thomas Wise
// Lab 07
// 19 Nov 2018

#ifndef LAB7_TWISE3_H
#define LAB7_TWISE3_H

#include <vector>
#include "RandomUtilities.h"

using std::vector;

void bubble(vector<double>& vec)
{
	int size = vec.size();
	double temp;
	bool done = false;

	while (!done)
	{
		done = true;
		for (int i = 0; i < (size - 1); i++)
		{
			if (vec[i] > vec[i + 1])
			{
				temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
				done = false;
			}
		}
	}
}

void insertion(vector<double>& vec)
{
	int size = vec.size();
	double temp;
	for (int i = 1; i < size; i++)
	{
		for (int n = 0; n < i; n++)
		{
			if (vec[n] > vec[i])
			{
				temp = vec[i];
				for (int j = i; j > n; j--)
				{
					vec[j] = vec[j-1];
				}
				vec[n] = temp;
				break;
			}
		}
	}
}

void selection(vector<double>& vec)
{
	double min;
	int minPos;
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		min = vec[i];
		minPos = i;
		for (int n = (i+1); n < size; n++)
		{
			if (vec[n] < min)
			{
				min = vec[n];
				minPos = n;
			}
		}
		vec[minPos] = vec[i];
		vec[i] = min;
	}
}

// Code for merge and mergeSort based on code from https://www.geeksforgeeks.org/merge-sort/
// Modified a little bit to work with vectors.
void merge(vector<double>& vec, int left, int right)
{
	int size = vec.size();
	int i, j, k;
	vector<double> l;
	vector<double> r;

	int middle = (left + right) / 2;
	for (int i = left; i < middle; i++)
	{
		l.push_back(vec[i]);
	}
	for (int i = middle; i < right; i++)
	{
		r.push_back(vec[i]);
	}

	i = 0;
	j = 0;
	k = left;
	while (i < l.size() && j < r.size())
	{
		if (l[i] <= r[j])
		{
			vec[k] = l[i];
			i++;
		}
		else
		{
			vec[k] = r[j];
			j++;
		}
		k++;
	}

	while (i < l.size())
	{
		vec[k] = l[i];
		i++;
		k++;
	}

	while (j < r.size())
	{
		vec[k] = r[j];
		j++;
		k++;
	}
}

void mergeSort(vector<double>& vec, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;

		mergeSort(vec, left, middle);
		mergeSort(vec, (middle + 1), right);

		merge(vec, left, right);
	}
}

void quickSort(vector<double>& vec)
{

}

#endif