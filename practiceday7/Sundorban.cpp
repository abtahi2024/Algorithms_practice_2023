#include<bits/stdc++.h>
using namespace std;
bool vis[50][50];
int dis[50][50];
vector<pair<int,int> >d={{0,1},{0,-1},{-1,0},{1,0}};
int n;
char a[50][50];
bool vaild(int ci,int cj)
{
    return ci>=0&&ci<n&&cj>=0&&cj<n&&a[ci][cj]!='T';
}
void bfs(int si,int sj)
{
    queue<pair<int,int> >q;
    q.push({si,sj});
    vis[si][sj]=true;
    dis[si][sj]=0;
    while (!q.empty())
    {
        pair<int,int>par=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ci=par.first+d[i].first;
            int cj=par.second+d[i].second;
            if(vaild(ci,cj)&&!vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                dis[ci][cj]=dis[par.first][par.second]+1;
                
            }
        }
    }
    
}
int main()
{
    while(cin>>n)
    {
        int si,sj,ci,cj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='S')
                {
                    si=i;
                    sj=j;
                }
                if(a[i][j]=='E')
                {
                    ci=i;
                    cj=j;
                
                }
            }
        }
       
        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));
        bfs(si,sj);
        
        cout<<dis[ci][cj];
    }



    return 0;
}


