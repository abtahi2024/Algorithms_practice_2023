#include<bits/stdc++.h>
using namespace std;
bool vis[55];
bool pathVisit[55];
vector<int>v[55];
bool ans;
void dfs(int p)
{
    vis[p]=true;
    pathVisit[p]=true;
    for(int cl:v[p])
    {
        if(pathVisit[cl])
        {
            ans=true;
            return;
        }
        if(!vis[cl])
        {
            dfs(cl);
        }
    }
    pathVisit[p]=false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(x)
            {
                v[i].push_back(j);
            }
            
        }
    }
    memset(vis,false,sizeof(vis));
    memset(pathVisit,false,sizeof(pathVisit));
    ans=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
 
        }
    }
    if(ans)
    {
        cout<<"1";
        
    }
    else
    {
        cout<<"0";
    }

    return 0;
}



