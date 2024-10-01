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
int main()
{
    ll n,e;
    cin>>n>>e;
    dsu_inlz(n);
    ll cnt=0;
    while(e--)
    {
        ll a,b;
        cin>>a>>b;
        ll lA=dsu_find(a);
        ll lB=dsu_find(b);
        if(lA==lB)
        {
            cnt++;
        }
        else 
        {
            dus_union_size(lA,lB);
        }
    }
    cout<<cnt<<endl;

    return 0;
}