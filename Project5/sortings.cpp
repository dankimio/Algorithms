#include "sortings.h"

// Despite the encapsulation, decomposition was made here to make it generally
// testable.
// (In real life, functions divide_and_merge() and merge() should be hidden (for
// example, private))

// Initial call of function.
void merge_sort(int *arr, int n);

// Recursive function to divide the array and merge it in current bounds [from,
// to].
void divide_and_merge(int *arr, int from, int to);

// Method to merge two sorted pieces of array to one sorted piece.
// Normally, first piece indexes are in bounds: [from, from + (to - from) / 2];
// second piece indexes are in bounds: [from + (to - from) / 2 + 1, to];
// method should make the array sorted in bounds [from, to] in O(n) time
// complexity.
void merge(int *arr, int from, int to);

// Implementation

void merge_sort(int *arr, int n) { divide_and_merge(arr, 0, n - 1); }

void divide_and_merge(int *arr, int from, int to) {
    if (from < to) {
        // Middle element
        int middle = (from + to) / 2;
        // Left
        divide_and_merge(arr, from, middle);
        // Right
        divide_and_merge(arr, middle + 1, to);
        // Merge two parts
        merge(arr, from, to);
    }
}

void merge(int *arr, int from, int to) {
    int middle = (from + to) / 2;

    // Auxiliary array
    int *temp = new int[to];

    int i = from;
    int j = middle + 1;
    int k = from;

    while (i <= middle && j <= to) {
        // Compare elements from two parts, update if needed
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    // Update left part
    while (i <= middle) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    // Update right part
    while (j <= to) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    // Copy from auxiliary to original array
    for (int i = from; i < k; i++) {
        arr[i] = temp[i];
    }

    // delete [] temp;
}

void array_generation(int result[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        result[i] = min + rand() % (max - min + 1);
    }
}

void results(int a[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

bool is_sort(int a[], int n) {
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            flag = false;
        }
    }
    return flag;
}
