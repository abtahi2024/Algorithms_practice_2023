#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
bool vt[1005];
int l[1005];
int pr[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vt[src] = true;
    l[src]=0;
    while (!q.empty())
    {
        int p=q.front();
        q.pop();
        for (int c:v[p])
        {
            if(vt[c]==false)
            {
            q.push(c);
            vt[c]=true;
            l[c]=l[p]+1;
            pr[c]=p;
            }
        }
        
    }
    
}

int main()
{
    int  n,e;
    cin>>n>>e;
    while (e--)
    {
      int a,b;
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int s,d;
        cin>>s>>d;
        memset(vt,false,sizeof(vt));
        bfs(s);
        if(!vt[d])
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<l[d]<<endl;
        }
    }
    


    return 0;
}