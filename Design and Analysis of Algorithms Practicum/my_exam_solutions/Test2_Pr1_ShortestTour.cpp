#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>

using namespace std;
unordered_set<int> st1;
unordered_map<int, list<int>> mp1;
int bfs_algo(int start, int end) {
    queue<int> qu;
    qu.push(start);
    st1.insert(start);

    int vl(0);
    while (!qu.empty()) {
        int s = qu.size();
        while (s--) {
            int cur = qu.front();
            st1.insert(cur);
            if (cur == end)
                return vl;
            for (const auto &child : mp1[cur])
                if (!st1.count(child))
                    qu.push(child);
            qu.pop();
        }
        ++vl;
    }
    return -1;
}

int main() {
    int N, M, a, b, K;
    cin >> N >> M;

    mp1.reserve(N);
    st1.reserve(N);

    while (M--) {
        cin >> a >> b;
        mp1[a].push_back(b);
    }

    cin >> K;

    vector<int> path(K);

    for (a = 0; a < K; ++a)
        cin >> path[a];

    int shortest(0);

    for (a = 0; a < K - 1; ++a) {
        for (b = a + 2; b < K; ++b)
            st1.insert(path[b]);

        int dist = bfs_algo(path[a], path[a + 1]);
        st1.clear();

        if (dist != -1)
            shortest += dist;
        else
            return cout << dist, 0;
    }
    return cout << shortest, 0;
}