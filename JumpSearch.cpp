#include <iostream>
#include <math.h>

using namespace std;

// jump search
int jumpSearch(int arr[], int x, int n)
{
    int step = sqrt(n);
    int prev = 0;
    while (arr[prev] < x) {
        cout << prev << " ";
        prev += step;
        if (prev >= n) {
            break;
        }
    }
    if (arr[prev] == x) {
        cout << prev << " ";
        return prev;
    }
    if (prev <= n) {
        cout << prev << " ";
    }
    prev = prev - step + 1;
    while (arr[prev] < x) {
        cout << prev << " ";
        prev++;
        if (prev == min(prev + step, n)) {
            cout << prev << " ";
            return -1;
        }
    }
    if (arr[prev] == x) {
        cout << prev << " ";
        return prev;
    }
    return -1;
}

int main() {
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 611, 612, 613 };
    int x = 614;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);

    if (index != -1) {
        cout << "\nNumber " << x << " is at index " << index;
    }
    else {
        cout << "\n" << x << " is not in array!";
    }
}