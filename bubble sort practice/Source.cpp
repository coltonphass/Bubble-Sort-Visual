#pragma warning(disable:6031)

// INCLUDES AND NAMESPACES
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

// DEFINES
#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

#define LIST_SIZE 20

// PROTOTYPES
void bubbleSort(int*);
void displayArray(int[], int);

int main() {
	// declare an array of numbers
	int numArray[LIST_SIZE] = { 20, 99, 45, 34, 12, 67, 89, 34, 26, 58,
								  90, 89, 3, 1, 56, 38, 79, 23, 56, 92 };

	// display the array before sorting
	cout << "BEFORE SORTING, THE ARRAY CONTAINS:" << endl;
	displayArray(numArray, LIST_SIZE);
	cout << endl;

	// sort the array
	bubbleSort(numArray);

	// display the array after sorting
	cout << "AFTER SORTING, THE ARRAY CONTAINS:" << endl;
	displayArray(numArray, LIST_SIZE);
	cout << endl;

	_getch();
	return 0;
}

void bubbleSort(int* numbersArray) {
    bool swap = TRUE;
    int pass = 1;  // Keep track of which pass we're on
    while (swap == TRUE) {
        cout << "\nPass " << pass << ":\n";
        swap = FALSE;
        for (int i = 0; i <= LIST_SIZE - 2; i++) {
            int j = i + 1;
            // Print current state
            cout << "Comparing positions " << i << " and " << j << ": ";
            for (int k = 0; k < LIST_SIZE; k++) {
                if (k == i) cout << "[" << numbersArray[k] << "] ";
                else if (k == j) cout << "[" << numbersArray[k] << "] ";
                else cout << numbersArray[k] << " ";
            }

            if (numbersArray[i] > numbersArray[j]) {
                int temp = numbersArray[j];
                numbersArray[j] = numbersArray[i];
                numbersArray[i] = temp;
                swap = TRUE;
                cout << " -> Swapped!\n";
            }
            else {
                cout << " -> No swap needed\n";
            }
        }
        pass++;
    }
    cout << "\nFinal array: ";
    for (int i = 0; i < LIST_SIZE; i++) {
        cout << numbersArray[i] << " ";
    }
    cout << endl;
}

void displayArray(int array[], int numElements) {
	cout << setiosflags(ios::left);
	for (int i = 0; i < numElements; i++) {
		cout << setw(3) << array[i];
	}
	cout << endl;
}