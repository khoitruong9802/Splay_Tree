#include <iostream>

using namespace std;

int interpolationSearch(int arr[], int left, int right, int x)
{
    if (left == right) {
        return -1;
    }
    int index = left + (x - arr[left]) * (right - left) / (arr[right] - arr[left]);
    if (index > right || index < left) {
        return -1;
    }
    cout << "We traverse on index: " << index << endl;
    if (arr[index] > x) {
        return interpolationSearch(arr, left, index - 1, x);
    } else if (arr[index] < x) {
        return interpolationSearch(arr, index + 1, right, x);
    }
    return index;
}

int main() {
    int arr[] = { 1,2,3,4,5,6,7,8,9,-1,-2,-3,-4,-9,0,99,55 };

    int n = sizeof(arr) / sizeof(arr[0]);
    int x =22;
    int result = interpolationSearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                    : cout << "Element is present at index " << result;
    return 0;
}