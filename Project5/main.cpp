#include "sortings.h"
#include <fstream>
#include <iostream>
#include <string>

/*
 Name + Surname: Daniil Kim
 Group: 201(1)
 Date: 16.10.2014
 Task: Merge sort
 IDE: Visual Studio
 */

void read_arrays();
void read_input(int &param, string message);
void copy_array(int array1[], int array2[], int n);
void sort_array(int array[], int n);

int main() {
    // TODO: make console application, use methods in sortings file
    /*
     Note: you can add your own methods and #include's in sortings,
     but you still need to use given methods
     DON'T CHANGE HEADER FILE
     */
    /*
     Write your console application here, you need to implement next features:
     1) read data from file "test_proekt_5.txt" (which should be located in the
     same directory with source files);
     test_proekt_5.txt file format:
     NT //first line - number of tests
     // then NT times
     Ni //number of elements in i test' array
     X1 X2 X3 ... XM //Ni elements of the array

     2) you need to output to console and to file output_proekt_5.txt:
     array before sorting
     array after sorting
     result of is_sort method to sorted array
     */

    // User's choice
    int choice;
    cout << "1. Generate an array\n2. Read from file" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        // Generate an array
        int array_size;
        read_input(array_size, "Enter array size: ");

        int min;
        read_input(min, "Enter minimum value: ");

        int max;
        read_input(max, "Enter maximum value: ");

        cout << endl;

        int *array;
        array = new int[array_size];

        array_generation(array, array_size, min, max);
        sort_array(array, array_size);

        delete[] array;
        break;
    case 2:
        // Read arrays from file
        read_arrays();
        break;

    default:
        cout << "Error" << endl;
        break;
    }

    // Wait
    system("pause");
}

// Read and sort arrays from file
void read_arrays() {
    string line;
    ifstream input_file;
    input_file.open("test_proekt_4.txt");

    if (input_file.is_open()) {
        // Get arrays count
        int n;
        input_file >> n;
        cout << "Arrays: " << n << "\n" << endl;

        // Read arrays
        for (int i = 0; i < n; i++) {
            // Get array size
            int array_size;
            input_file >> array_size;
            cout << "Array size: " << array_size << endl;

            int *array;
            array = new int[array_size];

            // Read array elements
            for (int j = 0; j < array_size; j++) {
                int element;
                input_file >> element;
                array[j] = element;
            }

            // Sort array
            sort_array(array, array_size);

            if (i != n - 1) {
                cout << endl;
            }

            // Clean up
            input_file.close();
            delete[] array;
        }
    } else {
        cout << "Unable to open" << endl;
    }
}

// Read integer input from the console
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

// Copy array1 to array2
void copy_array(int array1[], int array2[], int n) {
    for (int i = 0; i < n; i++) {
        array2[i] = array1[i];
    }
}

// Write to file
void write_array(int array_before[], int array_after[], int n) {
    cout << "OUTPUT!!!";
    ofstream output;
    output.open("output_proekt_5.txt");
    output << "Merge sort" << endl;

    output << "Array before" << endl;
    for (int i = 0; i < n; i++) {
        output << array_before[i] << " ";
    }
    output << endl;

    output << "Array after" << endl;
    for (int i = 0; i < n; i++) {
        output << array_after[i] << " ";
    }
    output << endl;

    output.close();
}

// Sort the array and pretty print the result
void sort_array(int array[], int n) {
    // Sort copied array, not the original one
    int *array_copy;
    array_copy = new int[n];

    // Print array
    cout << "Array before: " << endl;
    results(array, n);

    // Merge sort
    cout << "Merge sort: " << endl;
    copy_array(array, array_copy, n);
    merge_sort(array_copy, n);
    results(array_copy, n);
    cout << "Is sorted: " << endl;
    if (is_sort(array_copy, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    write_array(array, array_copy, n);

    // Clean up
    delete[] array_copy;
}
