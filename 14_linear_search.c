//Program created by GitHub Co-pilot

#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return the index
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int target = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in array\n");
    }

    return 0;
}

/* Output
Element is present at index 3
=== Code Execution Successful ===
