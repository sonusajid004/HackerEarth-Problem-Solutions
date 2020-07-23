#include <iostream>
#define ll long long 
using namespace std;
#define ff first
#define ss second
const int maxn=1000001;
pair<int,int> p[maxn*4];
int val[maxn];

void build(int ss,int se,int si)
{
    if(ss==se)
    {
        if(val[ss]%2)
        {
            p[si]={1,0};
        }
        else
        {
            p[si]={0,1};
        }
        return;
    }
    int mid = (ss+se)>>1;
    build(ss,mid,2*si);
    build(mid+1,se,2*si+1);
    p[si].ff=p[2*si].ff + p[2*si+1].ff;
    p[si].ss = p[2*si].ss + p[2*si+1].ss;
}

void update(int ss,int se,int si,int qi,int up)
{
    if(ss==se)
    {
        val[qi]= up;
        if(val[ss]%2)
        {
            p[si]={1,0};
        }
        else
        {
            p[si]={0,1};
        }
        return;
    }
    int mid = (ss+se)>>1;
    if(qi<=mid)
    update(ss,mid,2*si,qi,up);
    else
    update(mid+1,se,2*si+1,qi,up);
     p[si].ff=p[2*si].ff + p[2*si+1].ff;
    p[si].ss = p[2*si].ss + p[2*si+1].ss;
    
}
int getEven(int ss,int se,int qs,int qe,int si)
{
    if(ss>qe || se<qs)return 0;
    if(ss>=qs && se<=qe)
    {
        return p[si].ss;
    }
    int mid = (ss+se)>>1;
    int l = getEven(ss,mid,qs,qe,2*si);
    int r = getEven(mid+1,se,qs,qe,2*si+1);
    return l+r;
}
int getOdd(int ss,int se,int qs,int qe,int si)
{
    if(ss>qe || se<qs)return 0;
    if(ss>=qs && se<=qe)
    {
        return p[si].ff;
    }
    int mid = (ss+se)>>1;
    int l = getOdd(ss,mid,qs,qe,2*si);
    int r = getOdd(mid+1,se,qs,qe,2*si+1);
    return l+r;
}

int main()
{
    int n;
    cin>>n;

   for(int i=1;i<=n;i++)
   cin>>val[i];
     build(1,n,1);
  
   int q;
   cin>>q;
 
   while(q--)
   {
       int c,l,r;
       cin>>c>>l>>r;
       if(c==0)
       {
           if(val[l]%2==r%2)continue;
           else
           update(1,n,1,l,r);
    
       }
       else if(c==1)
       {
           cout<<getEven(1,n,l,r,1)<<endl;
       }
       else
       {
           cout<<getOdd(1,n,l,r,1)<<endl;
       }
       
   }
    
}
