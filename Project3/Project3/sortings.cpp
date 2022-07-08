#include "sortings.h"

// Sorting
void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int b = a[i];
        int j = i - 1; // Lalka

        while (b < a[j] && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = b;
    }
}

void binary_sort(int a[], int n) {
    int i = 1;
    while (i < n) {
        int left = 0;
        int right = i - 1;
        int center = (left + right) / 2;

        while (left != center) {
            if (a[center] > a[i]) {
                right = center - 1;
            } else {
                left = center;
            }
            center = (left + right) / 2;
        }

        while (a[left] < a[i]) {
            if (a[i] > a[right]) {
                left = right + 1;
            } else {
                left = right;
            }
        }
        int k = i;
        int p = a[i];

        while (k > left) {
            a[k] = a[k - 1];
            k--;
        }
        a[left] = p;
        i++;
    }
}

// Auxiliary
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
