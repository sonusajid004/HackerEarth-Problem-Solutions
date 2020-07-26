#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define MAX INT_MAX
#define vi vector<int>

vi a[100001];
int col[100001],vis[100001];


bool dfs(int node,int c)
{
    vis[node]=1;
    col[node]=c;
    for(int j:a[node])
    {
        if(vis[j]==0)
        {
            if(dfs(j,col[node]^1))
            return true;
        
        }
        else if(col[j]==col[node])
        return true;
    }
    return false;
}


int main()
{
    
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        memset(vis,0,sizeof(vis));
        memset(col,0,sizeof(col));
        int n,m;
        cin>>n>>m;
        int x,y,c=0;
        for(int i=1;i<=n;i++)a[i].clear();
        for(int i=1;i<=m;i++)
        cin>>x>>y,a[x].pb(y),a[y].pb(x);
        bool flag = false;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                c++;
                if(dfs(i,0))
                {
                    flag = true;
                    
                }
            }
        }
        if(!flag)
        cout<<"Scenario #"<<tc<<":\nNo suspicious bugs found!\n";
        else cout<<"Scenario #"<<tc<<":\nSuspicious bugs found!\n";
        
    }
    
}
