#include<bits/stdc++.h>
using namespace std;
// const int N=1e5+5;
bool vis[100][100];
int dis[100][100];
vector<pair<int, int>> d={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};
int n,m;
// char a[100][100];
bool valid(int ki,int kj)
{
    if(ki<0||ki>=n||kj<0||kj>=m)
    {
        return false;
    }
    return true;
}
void bfs(int ki,int kj)
{
    queue<pair<int,int>>q;
    q.push({ki,kj});
    vis[ki][kj]=true;
    dis[ki][kj]=0;
    while(!q.empty())
    {
        pair<int,int>pt=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int qi=pt.first+d[i].first;
            int qj=pt.second+d[i].second;
            if(valid(qi,qj) && !vis[qi][qj])
            {
                q.push({qi,qj});
                vis[qi][qj]=true;
                dis[qi][qj]=dis[pt.first][pt.second]+1;
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        // int n,m;
        cin>>n>>m;
        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));
        
        int ki,kj,qi,qj;
        cin>>ki>>kj>>qi>>qj;
         bfs(ki,kj);
            if(dis[qi][qj]==-1)
            {
               cout<<-1<<endl;
            }
            else
            {
                cout<<dis[qi][qj]<<endl;
            }
      
  
        // bfs(qi,qj);

        // if(ki==qi&&kj==qj)
        // {
        //     cout<<0<<endl;
        // }
        // if(!vis[ki][kj])
        // {
        //     cout<<-1<<endl;
        // }
        // else
        // {
        //     cout<<dis[ki][kj]<<endl;
        // }


    }
   
    return 0;
}




