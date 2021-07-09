#include <iostream>
#include<algorithm>
using namespace std;

int a[101];
int dp[101];
bool toN[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    dp[0] = a[1] - a[0];
    dp[1] = a[1] - a[0];
    toN[0] = true;

    for (int i = 2; i < n; i++) {
        int toPrev;
        if (toN[i - 1]) toPrev = dp[i - 1];
        else toPrev = dp[i - 2] + a[i] - a[i - 1];

        int toNext;

        if(i == n - 1) toNext = INT_MAX;
        else toNext = dp[i - 1] + a[i + 1] - a[i];

        if(toNext < toPrev) {
            dp[i] = toNext;
            toN[i] = true;
        } else {
            dp[i] = toPrev;
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
