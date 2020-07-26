#include<bits/stdc++.h>
using namespace std;
#define pb push_back


void dfs(int id,bool vis[],vector<int> v[])
{
    vis[id]=true;
    for(int j:v[id])
    {
        if(vis[j]==false)
        dfs(j,vis,v);
    }
}

int main()
{
	int n,t;
	cin>>n>>t;
	vector<int> v[n+1];
	for(int i=0;i<t;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    v[x].pb(y);
	    v[y].pb(x);
	}
	bool vis[n+1]{};
	int c=0;
	for(int i=1;i<=n;i++)
	if(vis[i]==false)
	{
	    c++;dfs(i,vis,v);
	}
	cout<<c;
	return 0;
}
