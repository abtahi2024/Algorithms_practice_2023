#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
// int lavel[1005];
// int parent[1005];
bool vis[1005];
bool ans;
void dfs(int s)
{
    vis[s]=true;
    for(int cl:v[s])
    {
       
        if(!vis[cl])
        {
            
            dfs(cl);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    // memset(lavel,-1,sizeof(lavel));
    // memset(parent,-1,sizeof(parent));
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}




