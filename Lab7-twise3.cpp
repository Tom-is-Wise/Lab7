// Lab7-twise3.cpp
// Thomas Wise
// Lab 07
// 19 Nov 2018

#include "Lab7-twise3.h"
#include "winTimer.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int seed, sizeOfList, sortMeth = 0;
	double minVal, maxVal;
	bool done;

	while (sortMeth < 6)
	{
		done = false;

		if (sortMeth == 0)
		{
			cout << "STL::sort the list (seed = 0 to stop):" << endl << endl;
		}

		else if (sortMeth == 1)
		{
			cout << "Bubble sort the list (seed = 0 to stop):" << endl << endl;
		}

		else if (sortMeth == 2)
		{
			cout << "Insertion sort the list (seed = 0 to stop):" << endl << endl;
		}

		else if (sortMeth == 3)
		{
			cout << "Selection sort the list (seed = 0 to stop):" << endl << endl;
		}

		else if (sortMeth == 4)
		{
			cout << "Merge sort the list (seed = 0 to stop):" << endl << endl;
		}

		else if (sortMeth == 5)
		{
			cout << "Quick sort the list (seed = 0 to stop):" << endl << endl;
		}

		while (!done)
		{
			cout << "Seed: ";
			cin >> seed;
			if (seed == 0)
			{
				cout << endl;
				done = true;
				sortMeth++;
				break;
			}
			cout << "Size of list: ";
			cin >> sizeOfList;
			cout << "Minimum value: ";
			cin >> minVal;
			cout << "Maximum value: ";
			cin >> maxVal;

			srand(seed);

			vector<double> testVec;
			for (int i = 0; i < sizeOfList; ++i)
			{
				testVec.push_back(randReal(minVal, maxVal));
			}
			if (sizeOfList < 10)
			{
				cout << "Unsorted: ( ";
				for (int i = 0; i < sizeOfList; i++)
				{
					cout << testVec[i] << " ";
				}
				cout << ")" << endl;
			}
			Timer get;
			
			if (sortMeth == 0)
			{
				get.start();
				sort(begin(testVec), end(testVec));
				get.stop();
			}

			else if (sortMeth == 1)
			{
				get.start();
				bubble(testVec);
				get.stop();
			}

			else if (sortMeth == 2)
			{
				get.start();
				insertion(testVec);
				get.stop();
			}

			else if (sortMeth == 3)
			{
				get.start();
				selection(testVec);
				get.stop();
			}

			else if (sortMeth == 4)
			{
				get.start();
				mergeSort(testVec, 0, (sizeOfList - 1));
				get.stop();
			}

			else if (sortMeth == 5)
			{
				get.start();
				quickSort(testVec);
				get.stop();
			}

			if (sizeOfList < 10)
			{
				cout << "Sorted: ( ";
				for (int i = 0; i < sizeOfList; i++)
				{
					cout << testVec[i] << " ";
				}
				cout << ")" << endl;
			}
			cout << "Sorted in " << get() << " seconds" << endl << endl;
		}
	}
	return 0;
}