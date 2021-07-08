#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1e9, NMAX=105;

int n, m, k;
char s[NMAX];
int p[NMAX][NMAX], ans[NMAX][NMAX][27];

int main() {
    cin >> s >> k >> m;
    n = strlen(s);
    memset(p, 0, sizeof(p));
    for (int i = 0; i < (int) m; ++i) {
        char c1[10], c2[10];
        int d;
        cin >> c1 >> c2 >> d;
        p[c1[0] - 'a'][c2[0] - 'a'] = d;
    }
    for (int i = 0; i < n; ++i)s[i] = s[i] - 'a';
    for (int i = 0; i < n+1; ++i)for (int j = 0; j < k+1; ++j)for (int f = 0; f < 27; ++f)ans[i][j][f] = -inf;
    for (int i = 0; i < 26; ++i)ans[0][1][i] = 0;
    ans[0][0][s[0]] = 0;
    int tmp;
    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < k+1; ++j)
            for (int f = 0; f < 26; ++f)
                if (ans[i][j][f] > -inf) {
                    for (int d = 0; d < 26; ++d) {
                        tmp = 1;
                        if (s[i + 1] == d) tmp = 0;
                        ans[i + 1][j + tmp][d] = max(ans[i + 1][j + tmp][d], ans[i][j][f] + p[f][d]);
                    }
                }
    int result = -inf;
    for (int i = 0; i < k+1; ++i)for (int j = 0; j < 26; ++j)result = max(result, ans[n - 1][i][j]);
    cout << result << endl;
    return 0;
}