// Name: Daniil Kim
// Group: 201(1)
// Date: 28.09.2014
// Bubble-sort
// Xcode 6 (Tested in Visual Studio)

#include <iostream>
#include "sortings.h"

using namespace std;

void read_input(int &param, string message);
void copy_array(int array1[], int array2[], int n);

int main(int argc, const char *argv[]) {
    int array_size;
    read_input(array_size, "Enter array size: ");

    int min;
    read_input(min, "Enter minimum value: ");

    int max;
    read_input(max, "Enter maximum value: ");

    int *array = new int[array_size];
    int *array_copy = new int[array_size];
    array_generation(array, array_size, min, max);
    cout << "Generated array: " << endl;
    results(array, array_size);

    int choice;
    read_input(choice,
               "\n1. Bubble sort\n2. Iverson 1\n3. Iverson 2\n4. Exit\n");

    switch (choice) {
    case 1:
        copy_array(array, array_copy, array_size);
        bubble_sort(array_copy, array_size);
        results(array_copy, array_size);
        break;
    case 2:
        copy_array(array, array_copy, array_size);
        bubble_iverson_1(array_copy, array_size);
        results(array_copy, array_size);
        break;
    case 3:
        copy_array(array, array_copy, array_size);
        bubble_iverson_2(array_copy, array_size);
        results(array_copy, array_size);
        break;
    default:
        break;
    }

    results(array, array_size);
    return 0;
}

void read_input(int &param, string message) {
    while (true) {
        cout << message;
        if (cin >> param) {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void copy_array(int array1[], int array2[], int n) {
    for (int i = 0; i < n; i++) {
        array2[i] = array1[i];
    }
}
