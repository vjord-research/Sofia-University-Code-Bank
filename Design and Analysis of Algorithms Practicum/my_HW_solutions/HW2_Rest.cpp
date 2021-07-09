#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int mxN = 1e5 + 5;

#define vr emplace_back
#define inp1(a, b, c) scanf("%d%d%d",&a,&b,&c)
#define inp2(a, b, c, d) scanf("%d%d%d%d",&a,&b,&c,&d)

typedef tuple<int, int, int> tp;

int n, m, rec, class1, dist[mxN];
bool indic[mxN];
vector<tp> adject[mxN];

bool method0(int eq) {
    fill(dist, dist + mxN, 1e9), dist[1] = 0;
    queue<int> q;
    q.push(1);
    int curr;

    while (!q.empty()) {
        curr = q.front(), q.pop(), indic[curr] = true;
        int v, c, t;
        for (const auto &child: adject[curr]) {
            tie(v, c, t) = child;
            if (c <= eq && dist[curr] + t < dist[v])
                q.push(v), dist[v] = dist[curr] + t;
        }
    }
    return rec >= dist[n];
}

int method1(int l = 0, int r = class1, int ans = -1) {
    while (l <= r) {
        int m = (l + r) >> 1;
        if (method0(m)) {
            if (ans == -1) ans = m;
            ans = min(ans, m), r = m-1;
        } else l = m + 1;
    }
    return ans;
}

void init() {
    inp1(n, m, rec);
    int u, v, c, t;
    while (m--) {
        inp2(u, v, c, t);
        class1 = max(class1, c);
        adject[u].vr(v, c, t);
    }
}

int main() {
    return init(), printf("%d", method1()), 0;
}


