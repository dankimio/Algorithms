//
//  main.cpp
//  Project1
//
//  Created by Danya Kim on 2014-09-21.
//  Copyright (c) 2014 Danya Kim. All rights reserved.
//

// Ким Даниил, группа 201
// Проект 1
// GNU++11, компилируется в Visual Studio

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
  cout << "Types info" << endl;
  cout << "float: " << sizeof(float) * 8 << endl;
  cout << "int: " << sizeof(int) * 8 << "\n" << endl;

start:
  // Float to binary
  union Convert {
    float f;
    int i;
  } c;

  // Get float from the terminal
  float my_float;
  while (true) {
    cout << "Enter a float number: ";
    if (cin >> my_float) {
      cin.clear();
      break;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
  c.f = my_float;

  // Conversion to binary
  bitset<4 * 8> bits = c.i;
  cout << "\nBinary representation:\n" << bits << endl;

  // Binary to float
  union Invert {
    int my_int;
    float my_float;
  } invert;

  // From inverted binary to int
  cout << "Inverted binary:" << endl;
  int sum = 0;
  for (int i = 31; i >= 0; i--) {
    cout << bits[31 - i];
    sum += (int)bits[i] * (int)pow(2, 31 - i);
  }

  // Output results
  cout << "\n\nResult:" << endl;
  invert.my_int = sum;
  cout << invert.my_float << endl;

  // One more time?
  cout << "\nRun one more time? (y/n) ";
  char choice;
  cin >> choice;
  if (choice == 'y') {
    goto start;
  }
}
