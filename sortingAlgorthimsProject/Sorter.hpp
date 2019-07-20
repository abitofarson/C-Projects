#ifndef _SORTER_HPP
#define _SORTER_HPP

#include "Timer.hpp"
using namespace std;
#include <vector>
#include <ctime>
#include <iostream>

int findIndexOfSmallest(const vector<int> &arr, int start);
int partition(vector<int>& theArray, int first, int last);
int sortFirstMiddleLast(vector<int>& theArray, int first, int last);
void order(vector<int>& theArray, int i, int j);

class Sorter
{
public:
	Sorter(int arraySize);
	vector<int> bubbleSort(const vector<int>& arr);
	vector<int> selectionSort(const vector<int>& arr);
	vector<int> insertionSort(const vector<int>& arr);
	vector<int> quickSort(vector<int>& theArray, int first, int last);
	void Run(int type);
	void doSort(int choice);

private:
	vector<int> m_array;
	bool m_listSorted;
};

Sorter::Sorter(int arraySize)
{
	srand(time(0));

	for (int i = 0; i < arraySize; i++)
	{
		m_array.push_back(rand() % 10000);
	}
	m_listSorted = false;
}

void Sorter::doSort(int choice)
{
	Timer timer;
	timer.Start();
	
	switch(choice)
	{
	case 1:
		cout << "Doing a SELECTION SORT of " << m_array.size() << " integers..." << endl;
		m_array = selectionSort(m_array);
		break;
	case 2:
		cout << "Doing a BUBBLE SORT of " << m_array.size() << " integers..." << endl;
		m_array = bubbleSort(m_array);
		break;
	case 3:
		cout << "Doing a INSERTION SORT of " << m_array.size() << " integers..." << endl;
		m_array = insertionSort(m_array);
		break;

	case 4:
		cout << "Doing a QUICK SORT of " << m_array.size() << " integers..." << endl;
		m_array = quickSort(m_array,0, m_array.size() - 1);
		break;

	default:
		cout << "Invalid choice passed to doSort()!" << endl;
	}

	m_listSorted = true;

	cout << "List has been sorted. Outcomes for searches may be different." << endl;
	cout << "First 5 values: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i << " = " << m_array[i] << endl;
	}
	cout << "Last 5 values: " << endl;
	for (int i = m_array.size() - 5; i < m_array.size(); i++)
	{
		cout << i << " = " << m_array[i] << endl;
	}

	cout << endl << "Done, time elapsed: " << timer.GetElapsedMilliseconds() << " milliseconds" << endl;
}

vector<int> Sorter::bubbleSort(const vector<int>& arr)
{
	// Bubble Sort
	vector<int> sorted = arr;
	unsigned int n = sorted.size();

	for (unsigned int i = 0; i < n - 1; i++)
	{
		for (unsigned int j = 0; j < n - i - 1; j++)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}

	return sorted;
}

vector<int> Sorter::selectionSort(const vector<int>& arr)
{
	vector<int> sorted = arr;

	int temp;

	for (int front = 0; front < sorted.size(); front++)
	{

		int smallest = findIndexOfSmallest(sorted, front);

		std::swap(sorted[front], sorted[smallest]);

	}

	return sorted;
}

vector<int> Sorter::insertionSort(const vector<int>& arr)
{
	vector<int> sorted = arr;
	unsigned int n = sorted.size();

	for (int unsorted = 1; unsorted < n; unsorted++)
	{

		int nextItem = sorted[unsorted];
		int loc = unsorted;
		while ((loc > 0) && (sorted[loc - 1] > nextItem))
		{
			// Shift sorted[loc - 1] to the right
			sorted[loc] = sorted[loc - 1];
			loc--;
		}  // end while

		sorted[loc] = nextItem; // Insert nextItem into sorted region
	}  // end for

	return sorted;
}

vector<int> Sorter::quickSort(vector<int>& theArray, int first, int last)
{
	// the smallest array quickSort will sort
	if (last - first + 1 < 10)
	{
		theArray = insertionSort(theArray);
	}
	else
	{
		// Create the partition: S1 | Pivot | S2
		int pivotIndex = partition(theArray, first, last);

		// Sort subarrays S1 and S2
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);
	}  // end if

	return theArray;

}  // end quickSort

int findIndexOfSmallest(const vector<int>& arr, int start)
{
	int smallestFound = start; // Index of smallest entry found so far
	for (int currentIndex = start+1; currentIndex < arr.size(); currentIndex++)
	{
		if (arr[currentIndex] < arr[smallestFound])
			smallestFound = currentIndex;
	}  // end for
	return smallestFound; // Index of smallest entry
}  // end findIndexOfSmallest

int partition(vector<int>& theArray, int first, int last)
{
	// Choose pivot using median-of-three selection
	int pivotIndex = sortFirstMiddleLast(theArray, first, last);

	// Reposition pivot so it is last in the array
	std::swap(theArray[pivotIndex], theArray[last - 1]);
	pivotIndex = last - 1;
	int pivot = theArray[pivotIndex];

	// Determine the regions S1 and S2
	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	bool done = false;
	while (!done)
	{
		// Locate first entry on left that is >= pivot
		while (theArray[indexFromLeft] < pivot)
			indexFromLeft = indexFromLeft + 1;

		// Locate first entry on right that is <= pivot
		while (theArray[indexFromRight] > pivot)
			indexFromRight = indexFromRight - 1;

		if (indexFromLeft < indexFromRight)
		{
			std::swap(theArray[indexFromLeft], theArray[indexFromRight]);
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;
		}
		else
			done = true;
	}  // end while

	   // Place pivot in proper position between S1 and S2, and mark its new location
	std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
	pivotIndex = indexFromLeft;

	return pivotIndex;
}  // end partition

int sortFirstMiddleLast(vector<int>& theArray, int first, int last)
{
	int mid = first + (last - first) / 2;
	order(theArray, first, mid); // Make theArray[first] <= theArray[mid]
	order(theArray, mid, last);  // Make theArray[mid] <= theArray[last]
	order(theArray, first, mid); // Make theArray[first] <= theArray[mid]

	return mid;
}  // end sortFirstMiddleLast

void order(vector<int>& theArray, int i, int j)
{
	if (theArray[i] > theArray[j])
		std::swap(theArray[i], theArray[j]); // Exchange entries
}  // end order

#endif
