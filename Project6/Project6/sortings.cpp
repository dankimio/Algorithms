#include "sortings.h"

void build_heap(int a[], int n);
void heapify(int a[], int n, int i);
int left(int i);
int right(int r);
void swap(int a[], int i, int j);

// Heap sort
void heap_sort(int a[], int n) {
    build_heap(a, n);
    int length = n - 1;
    while (length > 0) {
        swap(a, 0, length);
        heapify(a, length, 0);
        length--;
    }
}

// Build heap
void build_heap(int a[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(a, n, i);
    }
}

// Put elements of a in heap order
void heapify(int a[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int max = i;

    if (l < n && a[i] < a[l]) {
        max = l;
    }
    if (r < n && a[max] < a[r]) {
        max = r;
    }
    if (i != max) {
        swap(a, i, max);
        heapify(a, n, max);
    }
}

// Get left child
int left(int i) { return 2 * i + 2; }

// Get right child
int right(int i) { return 2 * i + 1; }

// Exchange elements at given indices
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Auxiliary methods

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
