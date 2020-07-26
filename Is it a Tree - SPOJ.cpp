#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define MAX INT_MAX
#define vi vector<int>

vi a[100001];
int dist[100001],vis[100001];


bool dfs(int node,int par)
{
    vis[node]=1;
    for(int j:a[node])
    {
        if(vis[j]==0)
        {
            if(dfs(j,node))
            return true;
        
        }
        else if(j!=par)
        return true;
    }
    return false;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int x,y,c=0;
    for(int i=1;i<=m;i++)
    cin>>x>>y,a[x].pb(y),a[y].pb(x);
    bool flag = false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            c++;
            if(dfs(i,-1))
            {
                flag = true;
                
            }
        }
    }
    if(c==1 && !flag)
    cout<<"YES";
    else cout<<"NO";
    
}
