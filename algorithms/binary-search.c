#include <stdio.h>

int binarySearch (int *array, int arraySize, int searchedElement) {
    int left = 0;
    int right = arraySize - 1;
    int mid;

    while (left <= right) {
        mid = left + right / 2;

        if (array[mid] == searchedElement) {
            return mid;
        }

        if (array[mid] < searchedElement) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return NULL;
}

int main() {
    return 0;
}