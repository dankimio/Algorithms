//
//  sortings.h
//  Project2
//
//  Created by Danya Kim on 2014-09-28.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

// Bubble sort
void bubble_sort(int a[], int n);
void bubble_iverson_1(int a[], int n);
void bubble_iverson_2(int a[], int n);

// Auxiliary methods
void array_generation(int result[], int n, int min, int max);
void results(int a[], int n);
bool is_sorted(int a[], int n);
