#include <iostream>
using namespace std;

void count_sort(int arr[], int n)
{
    // Step 1: Find the maximum element in the array
    int k = arr[0];
    for(int i = 0; i < n; i++) {
        k = max(k, arr[i]);
    }

    // Step 2: Initialize the count array with size (k + 1) and set all elements to 0
    int *count = new int[k + 1]();  // This initializes the count array with all zeros

    // Step 3: Increment count array based on the occurrences of each element
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Modify the count array by adding the previous counts to the current count
    for(int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Sort the array by placing elements in their correct position
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    // Step 6: Copy the sorted elements back into the original array
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Clean up the dynamically allocated memory
    delete[] count;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    count_sort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
