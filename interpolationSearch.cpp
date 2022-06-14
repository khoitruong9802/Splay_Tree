#include <iostream>

using namespace std;

int interpolationSearch(int arr[], int left, int right, int x)
{
    // if (left == right) {
    //     return -1;
    // }
    // int index = left + (x - arr[left]) * (right - left) / (arr[right] - arr[left]);
    // if (index > right || index < left) {
    //     return -1;
    // }
    // if (arr[index] == x) {
    //     return index;
    // } 
    // cout << "We traverse on index: " << index << endl;
    // if (arr[index] > x) {
    //     return interpolationSearch(arr, left, index - 1, x);
    // } else if (arr[index] < x) {
    //     return interpolationSearch(arr, index + 1, right, x);
    // }
    if (left <= right && x >= arr[left] && x <= arr[right]) {   
        int pos = left + (x - arr[left]) * (right - left) / (arr[right] - arr[left]);
        cout << "We traverse on index: " << pos << endl;
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x) {
            return interpolationSearch(arr, pos + 1, right, x);
        }
        if (arr[pos] > x) {
            return interpolationSearch(arr, left, pos - 1, x);   
        }
    }
    return -1;
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