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
int vis[MAX],cur_cc,cc[MAX];

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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,a,b;
        string s;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            vis[i]=0;
            cc[i]=0;
        ar[i].clear();
        }
        cur_cc=0;
       
        vector<pair<int,int>> v;
        for(int i=1;i<=k;i++)
        {
            cin>>a>>s>>b;
            if(s=="=")
            {
                ar[a].pb(b);ar[b].pb(a);
            }
            else
            {
                v.pb({a,b});
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                cur_cc++;
                dfs(i);
            }
        }
        bool flag = true;
        for(int i=0;i<v.size();i++)
        {
            a = v[i].ff;
            b = v[i].ss;
            if(cc[a]==cc[b])
            {
                flag = false;
                break;
            }
        }
        if(!flag)
        {
            cout<<"NO\n";
        }
        else cout<<"YES\n";
        
        
        
    }

    
    
}
