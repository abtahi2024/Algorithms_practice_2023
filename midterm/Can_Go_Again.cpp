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
    ll s;
    cin>>s;
    dis[s]=0;
    for(ll i=1;i<=n;i++)
    {
        for(Edge ed:el)
        {
            ll u,v,c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u]!=1e18&&dis[u]+c<dis[v])
            {
                dis[v]=dis[u]+c;
            }
        }
    }
        for(Edge ed:el)
        {
            ll u,v,c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u]!=1e18&&dis[u]+c<dis[v])
            {
                cout<<"Negative Cycle Detected"<<endl;
                return 0;
            }
        }
        ll t;
        cin>>t;
        for(ll i=1;i<=t;i++)
        {
            ll d;
            cin>>d;
            if(dis[d]==1e18)
            {
                cout<<"Not Possible"<<endl;
            }
            else
            {
                cout<<dis[d]<<endl;
            }
        }

    return 0;
}


