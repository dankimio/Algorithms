//
//  main.cpp
//  Project4
//
//  Created by Danya Kim on 2014-10-11.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

#include <iostream>
#include "sortings.h"

int main() {
    int *a;
    a = new int[10];

    for (int i = 0; i < 10; i++) {
        a[i] = 0;
    }

    counting_sort(a, 10);
}
