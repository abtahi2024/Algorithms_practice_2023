#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int >d[N];
bool vis[N];
int lv[N];
int part[N];
void bfs(int sr)
{
    queue<int>q;
    q.push(sr);
    vis[sr]=true;
    lv[sr]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int Cl:d[p])
        {
            if(!vis[Cl])
            {
                q.push(Cl);
                vis[Cl]=true;
                lv[Cl]=lv[p]+1;
                part[Cl]=p;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    int s=1;
    memset(vis,false,sizeof(vis));
    memset(lv,-1,sizeof(lv));
    memset(part,-1,sizeof(part));
    bfs(s);
    int k=lv[n];
    if(k== -1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<k+1<<endl;
        vector<int>pt;
        int x=n;
        while(x!= -1)
        {
            pt.push_back(x);
            x=part[x];
        }
        reverse(pt.begin(),pt.end());
        for(int v:pt)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
  

    return 0;
}



