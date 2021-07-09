#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t, dist[1000], path[1000];
bool used[1000], locked[1000];
vector<int> adj[1000];

void init()
{
    for(int i=0;i<n;++i)
    {
        used[i] = 0;
        dist[i] = 10000000;
    }
}

void bfs(int start, int finish)
{
    used[start] = 1;
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0;i<adj[x].size();++i)
        {
            if(!used[adj[x][i]] && !locked[adj[x][i]])
            {
                dist[adj[x][i]] = dist[x] + 1;
                used[adj[x][i]] = 1;
                q.push(adj[x][i]);
            }
        }
    }
}

int main() {
    int x, y, ans = 0;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>path[i];
        locked[path[i]] = 1;
    }
    locked[path[0]] = 0;
    for(int i=1;i<t;++i)
    {
        locked[path[i]] = 0;
        init();
        bfs(path[i-1], path[i]);
        if(!used[path[i]]) {
            cout<<"-1"<<endl;
            return 0;
        }
        ans += dist[path[i]];
    }
    cout<<ans<<endl;

}
