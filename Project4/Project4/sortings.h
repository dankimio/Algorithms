//
//  sortings.h
//  Project4
//
//  Created by Danya Kim on 2014-10-11.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std; // standart c++ namespace

void counting_sort(int a[], int n); // methods prototypes
void radix_sort10(int a[], int n);
void radix_sort256(int a[], int n);

void array_generation(int result[], int n, int min,
                      int max); // methods prototypes for main()
void results(int a[], int n);
bool is_sort(int a[], int n);