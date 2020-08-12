#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> ar[100001];
int vis[100001],in[100001],low[100001];
unordered_set<int> s;
int timer = 0;
void dfs(int node,int par = -1)
{
    in[node] = low[node] = timer;
    timer++;
    vis[node]=1;
    int children = 0;
    for(int child:ar[node])
    {
        if(child==par)continue;
        if(vis[child]==1)
        {
            low[node] = min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            children++;
            low[node] = min(low[node],low[child]);
            if(low[child]>=in[node] && par!=-1)
            s.insert(node);
                
        }
         
        
    }
    //cout<<children<<" "<<par<<endl;
    if(par==-1 && children>1)
    s.insert(node);
    
    
}


int main() {
   int n,m,x,y;
   
   while(1)
   {
       cin>>n>>m;
       if(n==0 && m==0)
       break;
      
       for(int i=1;i<=n;i++)
       ar[i].clear(),vis[i]=0;
       timer = 1;
      
       for(int i=0;i<m;i++)
       {
           cin>>x>>y;
           ar[x].pb(y);
           ar[y].pb(x);
       }
       s.clear();
       for(int i=1;i<=n;i++)
       if(vis[i]==0)
       dfs(i,-1);
       cout<<s.size()<<endl;
      
       
       
   }
   
   
}
