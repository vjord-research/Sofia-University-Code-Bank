#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isOK(int mid, int *arr, int n, int k)
{
    int pos = arr[0];

    int elements = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if (elements == k)
                return true;
        }
    }
    return 0;
}
int biggestMinDistance(int *arr, int n, int k)
{
    sort(arr, arr + n);
    int res = -1;
    int left = 1, right = arr[n - 1] - arr[0];
    while (left < right) {
        int mid = (left + right) / 2;
        if (isOK(mid, arr, n, k)) {
            res = max(res, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }
    return res;
}



int main()
{
    int cols, inp;
    cin >> cols >> inp;
    int *arr = new int[cols];
    for (int col = 0; col < cols; ++col) {
        cin >> arr[col];
    }
    if (inp!=2) {
        cout << biggestMinDistance(arr, cols, inp);
    }
    else
        cout << biggestMinDistance(arr, cols, inp)+1;
    return 0;
}