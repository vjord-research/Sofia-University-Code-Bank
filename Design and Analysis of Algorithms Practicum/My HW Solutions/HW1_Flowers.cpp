#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, D, x1, A, B;
const int inp = 1e5;
int rain[inp];
int rain1[inp];

bool inputCheck(int r)
{
    if (rain[0] > D || L - rain[r - 1] - 1 > D)
        return false;
    for (int i = 1; i < r; ++i)
        if (rain[i] ^ rain[i - 1] && rain[i] - rain[i - 1] > D)
        {
            return false;
        }
        return true;
}
int ans(-1);
void myFunc(int l = 1, int r = N)
{
    while (l <= r)
    {
        int m = (l + r) >> 1;
        sort(rain, rain + m);
        if (inputCheck(m))
            ans = m, r = m - 1;
        else
            l = m + 1;
        for (int i = 0; i < m; ++i)
            rain[i] = rain1[i];
    }
}

void intervalBuild()
{
    int i(0);
    rain[i++] = x1, rain1[i - 1] = x1;
    for (; i < N; ++i)
        rain[i] = (rain[i - 1] * 1LL * A + B) % (L + 1), rain1[i] = rain[i];
}

void init()
{
    cin >> N >> L >> D >> x1 >> A >> B;
    intervalBuild();
}

int main()
{
    init();
    myFunc();
    cout <<ans;
}