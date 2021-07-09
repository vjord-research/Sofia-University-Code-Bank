#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long lx;

int n;
string str;
vector<int> inp;
vector<lx> f;

void init() {
    cin >> str;
    n = str.size();
}

void Func1(int n) {
    f.resize(n + 1);
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
}

void Func2() {
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'm' || str[i] == 'w')
            printf("%d", 0), exit(0);
        if (str[i] == 'n' || str[i] == 'u') {
            int j = i + 1;
            for (; j < n && str[j] == str[j - 1]; ++j) {}
            int curr = j - i;
            inp.push_back(curr);
            i = j - 1;
        }
    }
}

int Func3(lx ress = 1) {
    for (int x: inp) ress = (ress * f[x] % MOD);
    return ress;
}

int main() {
    return init(), Func1(n), Func2(), printf("%d\n", Func3()), 0;
}