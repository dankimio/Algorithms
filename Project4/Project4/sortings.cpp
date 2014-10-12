//
//  sortings.cpp
//  Project4
//
//  Created by Danya Kim on 2014-10-11.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

#include "sortings.h"

bool verify_array(int a[], int n);
int max_value(int a[], int n);
void copy_arrays(int array1[], int array2[], int n);

void counting_sort(int a[], int n) {
    // Throw exception unless valid
    if (!verify_array(a, n)) {
        throw invalid_argument("Array elements should be less than zero.");
    }

    int max = max_value(a, n);

    int *b;
    b = new int[n];

    int *c;
    c = new int[max + 1];

    // Fill array with 0s
    for (int i = 0; i <= max; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }

    for (int j = 0; j <= max; j++) {
        c[j] += c[j - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] -= 1;
    }

    // Clean up
    copy_arrays(b, a, n);
    delete[] b;
    delete[] c;
}

void radix_sort10(int a[], int n) {
    // TODO: write your radix sort here (10 number system, only positive
    // numbers)
}

void radix_sort256(int a[], int n) {
    // TODO: write your radix sort here (256 number system, only positive
    // numbers)
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
        if (a[i + 1] > a[i]) {
            flag = false;
        }
    }
    return flag;
}

// Auxiliary

// Elements should be > 0
bool verify_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            return false;
        }
    }
    return true;
}

// Max array value, assuming elements are positive
int max_value(int a[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Copy array1 to array2
void copy_arrays(int array1[], int array2[], int n) {
    for (int i = 0; i < n; i++) {
        array2[i] = array1[i];
    }
}