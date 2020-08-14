#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int k;

long long dp[100001],pre[100001];
long long int getAns(int n)
{
    if(n==0)
    return 1;
    long long int x=0,y=0;
   
    if(dp[n]!=-1)
    {
        return dp[n];
    }
     x = getAns(n-1)%mod;
    
    if(n>=k)
    y=getAns(n-k)%mod;
    
    return dp[n]=(x%mod+y%mod)%mod;
}

void init()
{
    int maxn=100001;
    memset(dp,-1,sizeof(dp));
    pre[0]=1;dp[0]=1;
    for(int i=1;i<maxn;i++)
    {
        pre[i] = (getAns(i)%mod+pre[i-1]%mod)%mod;
    }
    
}

int main()
{
    int t;
    cin>>t>>k;
    init();
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(pre[b]-pre[a-1]+mod)%mod<<endl;
        
    }
}
