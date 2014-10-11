//
//  sortings.h
//  Project3
//
//  Created by Danya Kim on 2014-10-05.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

void insertion_sort(int a[], int n);
void binary_sort(int a[], int n);

void array_generation(int result[], int n, int min, int max);
void results(int a[], int n);
bool is_sort(int a[], int n);