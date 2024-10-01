#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
// bool vis[N];
int dr[N],dj[N];

void bfs(int s,int level [])
{
    queue<int>q;
    q.push(s);
    level[s]=0;
    while (!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int cl:v[p])
        {
            if(level[cl]==INT_MAX)
            {
                level[cl]=level[p]+1;
                q.push(cl);
            }
        }
    }
    
}
int main()
{
  int n,e;
  cin>>n>>e;
  while (e--)
  {
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int x,y,k;
  cin>>x>>y>>k;

  for(int i=0;i<n;i++)
  {
    dr[i]=INT_MAX;
    dj[i]=INT_MAX;
  }

  bfs(x,dr);
  bfs(y,dj);
  for(int i=0;i<n;i++)
  {
    if(dr[i]<=k&&dj[i]<=k)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    
  }

        cout<<"NO"<<endl;


  


    return 0;
}




