//
//  sortings.cpp
//  Project4
//
//  Created by Danya Kim on 2014-10-11.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

#include "sortings.h"

void counting_sort(int a[], int n) {
    int *c;
    c = new int[n];

    // Fill array with 0s
    for (int i = 0; i < n; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        c[a[i]] = c[a[i]] + 1;
    }

    for (int j = 0; j < n; j++) {
        c[j] = c[j] + c[j - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << "Hello" << endl;
    }
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
    // TODO: you need to provide your array generation
}

void results(int a[], int n) {
    // TODO: you need to output array, use standart c++ output
}

bool is_sort(int a[], int n) {
    // TODO: you need to check out your array is sorted or not
    // return false or true;
    return true;
}