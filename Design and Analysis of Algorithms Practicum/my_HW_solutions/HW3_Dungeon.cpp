#include <cstdio>
#include <vector>

using namespace std;

#define s2(a, b) scanf("%d%d", &a,&b)
#define s3(a, b, c) scanf("%d%d%d", &a,&b,&c)

#define emb emplace_back
#define ff first
#define ss second
typedef pair<int, int> pii;

int n, m;

const int MXN = 1e5 + 5;

vector<pii> edges[MXN];
int par[MXN], r[MXN];

void initD() {
    for (int i = 0; i < n; ++i) par[i] = i;
}

int find(int v) {
    if (v == par[v]) return v;
    return find(par[v]);
}

void uu(int u, int v) {
    if (r[u] < r[v]) swap(u, v);
    par[v] = u;
    if (r[u] == r[v]) ++r[u];
}

int addEdges(int ans = 0) {
    initD();
    for (int i = 0; i < n; ++i)
        for (const auto &e:edges[i]) {
            int u = find(e.ff), v = find(e.ss);
            if (u == v) return ans = i, ans;
            uu(u, v);
        }
    return ans;
}

int main() {
    s2(n, m);
    int u, v, lvl;

    for (int i = 0; i < m; ++i)
        s3(u, v, lvl), edges[lvl].emb(u, v);

    return printf("%d\n", addEdges()), 0;
}


