#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
bool vt[1005];
int l[1005];
// int pr[1005];
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
            // pr[c]=p;
            }
        }
        
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
     int level;
    cin >> level;
    memset(vt,false,sizeof(vt));
   
    bfs(0);
    vector<int>b;
    for(int i=0;i<n;i++)
    {
        if(l[i]==level)
        {
            b.push_back(i);
        }
       
    }
    sort(b.begin(),b.end(),greater<int>());
    //  cout<<level;
     for(int v:b)
     {
        cout<<v<<" ";
     }

    return 0;
}