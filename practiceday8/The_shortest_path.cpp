#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
vector<int>v[N];
bool vis[N];
int dis[N];
int parent[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int cl:v[par])
        {
            if(!vis[cl])
            {
                q.push(cl);
                vis[cl]=true;
                dis[cl]=dis[par]+1;
                parent[cl]=par;
            }
        }
    }
}
int main()
{
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // int s,d;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    bfs(s);
    if(!vis[d])
    {
        cout<<"-1"<<endl;
    }
    else
    {
        
        int x=d;
        vector<int>pat;
        while(x!=-1)
        {
            pat.push_back(x);
            x=parent[x];
        }
        reverse(pat.begin(),pat.end());
        cout<<dis[d]<<endl;
        for(int b:pat)
        {
            cout<<b<<" ";
        }
    }
    return 0;
}



