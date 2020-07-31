#include <bits/stdc++.h>
#define vi vector<int>
#define ff first
#define ss second
#define vpi vector<pair<int,int>>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define MAX 1000001
using namespace std;

vi ar[MAX];
int vis[MAX],cur_cc,cc[MAX],dist[MAX],level[MAX];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=1;
    dist[src]=0;
    level[dist[src]]++;
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        for(int child:ar[c])
        {
            if(vis[child]==0){
            vis[child]=1;
            q.push(child);
            dist[child]=dist[c]+1;
            level[dist[child]]++;}
        }
    }
}

void dfs(int node)
{
    vis[node]=1;
    cc[node]=cur_cc;
    for(int child:ar[node])
    {
        if(vis[child]==0)
        dfs(child);
    }
}

int main() {
    FIO;
    int n,m,a,b,src,d,q;
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        ar[a].pb(b),ar[b].pb(a);
        
    }
    cin>>q;
    while(q--)
    {
        cin>>src>>d;
        for(int i=0;i<=n;i++)
        level[i]=0,vis[i]=0;
        
        bfs(src);
        cout<<level[d]<<endl;
    }
    
    
}
