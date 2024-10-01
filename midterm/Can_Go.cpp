#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll,ll>>v[1005];
ll dis[1005];
class cmp
{
    public:
    bool operator()(pair<ll,ll>a,pair<ll,ll>b)
    {
        return a.second>b.second;
    }
};
void dijkstra(int s)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp>pq;
    pq.push({s,0});
    dis[s]=0;
    while(!pq.empty())
    {
        pair<ll,ll>pt=pq.top();
        pq.pop();
        ll n=pt.first;
        ll c=pt.second;
        for(pair<ll,ll>cl:v[n])
        {
            ll cn=cl.first;
            ll cc=cl.second;
            if(c+cc<dis[cn])
            {
                dis[cn]=c+cc;
                pq.push({cn,dis[cn]});
            }
        }
    }
}
int main()
{
    ll n,e;
    cin>>n>>e;
    while(e--)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
    }
    int s;
    cin>>s;
    for(ll i=0;i<=n;i++)
    {
        dis[i]=1e18;
    }
    dijkstra(s);
    ll t;
    cin>>t;
    for (ll i = 1; i <=t; i++)
    {
        ll d,dw;
        cin>>d>>dw;
        if(dis[d]<=dw)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
        


    return 0;
}