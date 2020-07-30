#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

int vis[100001],dist[100001];
vi ar[100001];
vi primes;

bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    if(n%i==0)
    return 0;
    return true;
}


bool isValid(int a,int b)
{
    int c=0;
    while(b>0)
    {
        if(a%10!=b%10)
        c++;
        a/=10;b/=10;
    }
    return c==1;
}

void buildGraph()
{
    
    for(int i=1000;i<=9999;i++)
    {
        if(isPrime(i))
        primes.pb(i);
    }
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            int a = primes[i];
            int b = primes[j];
            if(isValid(a,b))
            {
                ar[a].pb(b);ar[b].pb(a);
            }
        }
    }
    
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    dist[s]=0;
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        for(int child:ar[a])
        {
            if(vis[child]==0){
            vis[child]=1;
            dist[child]=dist[a]+1;
            q.push(child);
            }
        }
    }
}


int main() {
    
    int t,a,b,n,m;
    cin>>t;
    buildGraph();
    while(t--)
    {
        cin>>a>>b;
        for(int i=1000;i<=9999;i++)
        {
            dist[i]=-1;
            vis[i]=0;
        }
        
        bfs(a);
        if(dist[b]==-1)
        {
            cout<<"Impossible\n";
        }
        else
        {
            cout<<dist[b]<<"\n";
        }
        
        
    }
    
    
}
