#include<bits/stdc++.h>
using namespace std;

bool vis[1005];
int dis[1005];
vector<int>v[1005];


void bfs( int x,int n)
{
    queue<int>q;
    q.push(x);
    vis[x]=true;
    dis[x]=0;
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
            }
        }
       
    }

}

int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int val;cin>>val;
            if(val==1)
            {
                v[i].push_back(j);
            }
        }
    }
    bfs(x,n);
    for(int i=1;i<=n;i++)
    {
        if(i==x)
        {
            cout<<"0 ";
        }
        else if(!vis[i])
        {
            cout<<"-1 ";
        }
        else
        {
            cout<<dis[i]<<" ";
        }
       
    }
    cout<<endl;

    return 0;
}




