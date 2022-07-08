#include "sortings.h"

// Bubble sort
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void bubble_iverson_1(int a[], int n) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (i < n && !flag) {
            flag = true;
            for (int j = 0; j < n - i; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
                flag = false;
            }
        }
    }
}

void bubble_iverson_2(int a[], int n) {
    int i = 0;
    while (i < n - 1) {
        int bound = n - 1;
        int t = 0;

        for (int j = 0; j < bound; j++) {
            if (i < bound) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    t = i;
                }
            } else {
                if (t == 0) {
                    break;
                } else {
                    bound = t;
                    i++;
                }
            }
        }

        i++;
    }
}

// Auxiliary
void array_generation(int result[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        result[i] = min + rand() % (max - min + 1);
    }
}

void results(int result[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

bool is_sorted(int a[], int n) {
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i]) {
            flag = false;
        }
    }
    return flag;
}
