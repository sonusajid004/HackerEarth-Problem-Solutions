#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define MAX INT_MAX
#define vi vector<int>

vi a[1001];
int dist[1001],vis[1001];


void dfs(int node,int len)
{
    vis[node]=1;
    dist[node] = len+1;
    for(auto j:a[node])
    {
        if(vis[j]==0)
        dfs(j,dist[node]+1);
    }
}


int main()
{
    int n;
    cin>>n;
    int x,y;
    for(int i=1;i<=n-1;i++)
    cin>>x>>y,a[x].pb(y),a[y].pb(x);
    
    dfs(1,0);
    int q;
    cin>>q;
    int ans = -1,val = MAX;
    while(q--)
    {
        int id;
        cin>>id;
        if(dist[id]<val)
        {
            ans = id;
            val  = dist[id];
        }
        else if(dist[id]==val)
        {
            ans = min(ans,id);
        }
    }
    cout<<ans;
    
    
    
}
