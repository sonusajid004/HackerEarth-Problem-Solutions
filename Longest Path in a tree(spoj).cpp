#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

int vis[10001];
vi ar[10001];
int maxD,maxNode;
void dfs(int node,int d)
{
    vis[node]=1;
    
    if(maxD<d)
    {
        maxD=d;maxNode = node;
    }
    
    for(int child:ar[node])
    {
       
        if(vis[child]==0)
        dfs(child,d+1);
    }
}

int main() {
    
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        ar[a].pb(b);ar[b].pb(a);
    }
    
    maxD=-1;
    
    dfs(1,0);
  
    maxD=-1;
   for(int i=1;i<=n;i++)vis[i]=0;
    dfs(maxNode,0);
    cout<<maxD;
    
    
    
}
