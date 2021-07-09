#include <iostream>
#include <algorithm>
using namespace std;
int parent[int(1e5)+5], n, m, q[int(1e5)+5], taken[int(1e5)+5];

struct Edge{
    int from,to,weight;

    bool operator <(const Edge &target)const{
        return this->weight < target.weight;
    }
}edges[int(1e6)+5];

int findRoot(int x)
{
    if(parent[x] == x){
        return x;
    }

    return parent[x] = findRoot(parent[x]);
}

void init(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
        parent[i] = i;
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++){
        scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].weight);
    }
}

void solve(){
    int ans = 0, br = 0;

    sort(edges,edges+m);

    for(int i=0;i<m;i++){
        int from = edges[i].from - 1;
        int to = edges[i].to - 1;

        int root1 = findRoot(from);
        int root2 = findRoot(to);

        if(q[from] > q[to] && !taken[to] && root1 != root2){
            taken[to] = 1;
            parent[root1] = root2;
            ans += edges[i].weight;
            br++;
        }
    }

    if(br == n-1){
        printf("%d\n",ans);
    }else{
        printf("-1\n");
    }
}

int main()
{
    init();
    solve();
}
