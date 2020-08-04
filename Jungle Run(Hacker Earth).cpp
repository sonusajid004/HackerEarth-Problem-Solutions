#include <bits/stdc++.h>

using namespace std;

int n;
char a[31][31];
int vis[31][31],dist[31][31];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


bool isValid(int x,int y)
{
    if(x<1||x>n||y<1||y>n)
    return false;
    if(vis[x][y]==1 || a[x][y]=='T')return false;
    
    return true;
}

void bfs(int x, int y)
{
    dist[x][y]=0;
    vis[x][y]=1;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    
    while(!q.empty())
    {
        int curX= q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(isValid(curX+dx[i],curY+dy[i]))
            {
                dist[curX+dx[i]][curY+dy[i]] = dist[curX][curY] + 1;
                vis[curX+dx[i]][curY+dy[i]] = 1;
                q.push({curX+dx[i],curY+dy[i]});
            }
        }
    }
    
}


int main() {
    
    cin>>n;
    int e_x,e_y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
        cin>>a[i][j];
        if(a[i][j]=='E')
        {
            e_x=i,e_y=j;
        }
        }
        
    }
    
    bfs(1,1);
    cout<<dist[e_x][e_y];
    
    
    
}
