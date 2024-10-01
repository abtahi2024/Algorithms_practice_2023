#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e5+5;
int par[N];
int gs[N];
void dsu_inlz(ll n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=-1;
        gs[i]=1;
    }
}
int dsu_find(ll node)
{
    if(par[node]==-1)
    {
        return node;
    }
    ll l=dsu_find(par[node]);
    par[node]=l;
    return l;
}
void dus_union_size(ll n1,ll n2)
{
    ll lA=dsu_find(n1);
    ll lB=dsu_find(n2);
    if(gs[lA]>gs[lB])
    {
        par[lB]=lA;
        gs[lA]+=gs[lB];
    }
    else
    {
        par[lA]=lB;
        gs[lB]+=gs[lA];
    }
}
class parson
{
    public:
    ll a,b,w;
    parson(ll a,ll b,ll w)
    {
        this->a=a;
        this->b=b;
        this->w=w;
    }
};
bool cmp(parson a,parson b)
{
    return a.w<b.w;
}
int main()
{
    ll n,e;
    cin>>n>>e;
    dsu_inlz(n);
    vector<parson>el;
    while(e--)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        el.push_back(parson(a,b,w));
    }
    sort(el.begin(),el.end(),cmp);
    ll tc=0;
    ll cnt=0;
    for(parson ed:el)
    {
        ll lA=dsu_find(ed.a);
        ll lB=dsu_find(ed.b);
        if(lB==lA)
        {
            continue;
        }
        else
        {
            dus_union_size(ed.a,ed.b);
            tc+=ed.w;
            cnt++;
        }
    }
    if(cnt<n-1)
    {
        cout<<"Not Possible"<<endl;
    }
    else
    {
        ll rd=el.size()-cnt;
        cout<<rd<<" " <<tc<<endl;
    }
    
    return 0;
}