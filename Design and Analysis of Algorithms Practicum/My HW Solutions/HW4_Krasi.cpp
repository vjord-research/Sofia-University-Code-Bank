#include<iostream>
#include<deque>
#include<cmath>
using namespace std;
const int nmax=1e5+42;
int n,k;
int inp[nmax];
int zeros[nmax],pref[nmax];
deque<int> q;
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
        zeros[i]=zeros[i-1]+(inp[i]==0);
        pref[i]=pref[i-1]+inp[i];
    }
    q.push_back(1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(zeros[i]-zeros[q.front()-1]>k)q.pop_front();
        while(q.size()&&pref[i-1]<pref[q.back()-1])q.pop_back();
        q.push_back(i);
        if(q.size())ans=max(ans,pref[i]-pref[q.front()-1]);
    }
    cout<<ans<<endl;
    return 0;
}