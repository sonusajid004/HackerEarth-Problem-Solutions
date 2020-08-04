#include <bits/stdc++.h>

using namespace std;


class edge
{
    public:
    int a,b,w;
};
edge ar[100000];

int par[100001];

bool cmp(edge x,edge y)
{
    return x.w<y.w;
}

int find(int x)
{
    if(par[x]<0)
    {
        return x;
    }
    
    return par[x] = find(par[x]);
}

void union1(int x,int y)
{
    x = find(x),y=find(y);
    if(par[x]<par[y])
    {
        par[x]+=par[y];
        par[y]=x;
    }
    else
    {
        par[y]+=par[x];
        par[x]=y;
    }
}




int main() {
  int n,m,a,b,w;
  cin>>n>>m;
  for(int i=0;i<=n;i++)par[i]=-1;
  
  for(int i=0;i<m;i++)
  {
      cin>>ar[i].a>>ar[i].b>>ar[i].w;
  }
  
  sort(ar,ar+m,cmp);
  
  int cnt=0,sum=0;
  for(int i=0;i<m;i++)
  {
      
      int x = ar[i].a,y=ar[i].b,w = ar[i].w;
      x = find(x),y=find(y);
      if(x!=y)
      {
          union1(x,y);
          
          sum+=w;
          cnt++;
          if(cnt==n-1)
          break;
      }
  }
  cout<<sum;
  
  
  
    
    
}
