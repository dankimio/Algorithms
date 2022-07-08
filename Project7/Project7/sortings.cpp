#include "sortings.h"
#include <random>
#include <iostream>

// Name: Daniil Kim
// Group: 201(1)
// IDE: Visual Studio

// This is what you need to do this time.
// Implement these functions and link their invokes together.
// All (!) functions that are not described in header should
// be used in other functions!

// You are welcome to add some functions but NOT TO CHANGE EXISTING
// FUNCTIONS SIGNATURES.

// Quick-sort is a pivot-based sort algorithm that uses O(1) ADDITIONAL SPACE
// and works in average O(n * log(n)) time complexity. O(n * n) is the worst case.
// depth - recursion depth, leaves - number of leaves in recursion tree

// Quicksort with middle element in array as pivot
void quicksort::quicksort_middle(int* arr, int n, int& depth, int& leaves) {
	recursive_call_qsort(arr, 0, n - 1, get_middle_pivot, depth, leaves);
}

// Quicksort with last element in array as pivot
void quicksort::quicksort_last(int* arr, int n, int& depth, int& leaves) {
	recursive_call_qsort(arr, 0, n - 1, get_last_pivot, depth, leaves);
}

// Quicksort with random pivot
void quicksort::quicksort_rand(int* arr, int n, int& depth, int& leaves) {
	recursive_call_qsort(arr, 0, n - 1, get_rand_pivot, depth, leaves);
}

// Getting position of middle pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_middle_pivot(int from, int to) {
	return (from + to) / 2;
}

// Getting position of last pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_last_pivot(int from, int to) {
	return to;
}

// Getting position of random pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_rand_pivot(int from, int to) {
	return from + rand() % (to - from + 1);
}

// Rearranges values in the array using pivot in the current bounds
//
// Additional space: O(1)
// Complexity: O(n)
// RETURNS: new position of the pivot in the array.
int quicksort::recompute_with_pivot(int* arr, int from, int to, int pivot_pos) {
	int pointer = from;

	for (int i = from; i <= to; i++) {
		if (arr[i] <= arr[to]) {
			int temp = arr[i];
			arr[i] = arr[pointer];
			arr[pointer] = temp;

			pointer++;
		}
	}

	return pointer - 1;
}

// Recursive call for qsort that sorts the array
// in the current bounds
//
// Additional space: O(1)
// Complexity: O(n*log(n)) - average. O(n*n) - the worst case.
void quicksort::recursive_call_qsort(int* arr, int from, int to, pivot_chooser pivot_chooser, int& depth, int& leaves) {
	if (from < to) {
		int local = depth;
		local++;

		int p = recompute_with_pivot(arr, from, to, pivot_chooser(from, to));
		recursive_call_qsort(arr, from, p - 1, pivot_chooser, local, leaves);
		recursive_call_qsort(arr, p + 1, to, pivot_chooser, local, leaves);

		leaves++;
		if (local > depth) {
			depth++;
		}
	}
}

void print_array(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int n = 10;
	int arr[10] = { 4, 4, 2, 1, 3, 6, 3, 1, 4, 9 };
	print_array(arr, n);

	int depth, leaves;
	depth = 0;
	leaves = 0;

	quicksort::quicksort_rand(arr, n, depth, leaves);
	print_array(arr, n);

	cout << "Leaves: " << leaves << endl;
	cout << "Depth: " << depth << endl;

	system("pause");
}
