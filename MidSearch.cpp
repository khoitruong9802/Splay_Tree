#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    int index = left + (right - left) / 2;
    if (index == right + 1 || index == left - 1) {
        return -1;
    }
    cout << "We traverse on index: " << index << endl;
    if (arr[index] > x) {
        return binarySearch(arr, left, index - 1, x);
    } else if (arr[index] < x) {
        return binarySearch(arr, index + 1, right, x);
    }
    return index;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                    : cout << "Element is present at index " << result;
    return 0;
}