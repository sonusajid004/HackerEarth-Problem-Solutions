#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

int vis[100001],dist[100001];
vi ar[100001];
int maxD,maxNode;

int main() {
    
    int t,a,b,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)vis[i]=0,ar[i].clear(),dist[i]=-1;
        
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            ar[a].pb(b);ar[b].pb(a);
        }
        queue<int> q;
        dist[1]=0;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            int node = q.front();
            
            q.pop();
            for(auto j:ar[node])
            {
                if(vis[j]==0)
                {
                    dist[j]=dist[node]+1;
                    vis[j]=1;
                    q.push(j);
                }
            }
        }
        cout<<dist[n]<<endl;
    }
    
    
}
