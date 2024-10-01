#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
    public:
    ll u,v,c;
    Edge(ll u,ll v,ll c)
    {
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
ll dis[1005];
int main()
{
    ll n,e;
    cin>>n>>e;
    vector<Edge>el;
    while(e--)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        el.push_back(Edge(u,v,c));
    }
    for(ll i=1;i<=n;i++)
    {
        dis[i]=1e18;
    }
    dis[1]=0;
    for (ll i = 1; i <=n-1; i++)
    {
        for(Edge ed:el)
        {
            int u,v,c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u]<3000 && dis[u]+c<dis[v])
            {
                dis[v]=dis[u]+c;
            } 
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==1e18)
        {
            cout<<30000<<" ";
        }
        else
        {
            cout<<dis[i]<<" ";
        }
    }
    



    return 0;
}