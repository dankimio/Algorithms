//
//  sortings.h
//  Project5
//
//  Created by Danya Kim on 2014-10-16.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std; // standart c++ namespace

void merge_sort(int a[], int n); // methods prototypes

void array_generation(int result[], int n, int min,
                      int max); // methods prototypes for main()
void results(int a[], int n);
bool is_sort(int a[], int n);