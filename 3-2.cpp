#include <iostream>
using namespace std;


int recursiveSum(int arr[], int size) {
    if (size == 0)
        return 0; 
    else
        return arr[size - 1] + recursiveSum(arr, size - 1); 
}

int iterativeSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;

    
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Array size must be greater than 0.\n";
        return 0;
    }


    int* arr = new int[size];

   
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int recSum = recursiveSum(arr, size);
    int iterSum = iterativeSum(arr, size);

    cout << "\nSum calculated using recursion: " << recSum << endl;
    cout << "Sum calculated using iteration: " << iterSum << endl;
    cout<<"khush_24CE135";