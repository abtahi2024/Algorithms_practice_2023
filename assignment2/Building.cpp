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
class wifi
{
    public:
    ll a,b,w;
    wifi(ll a,ll b,ll w)
    {
        this->a=a;
        this->b=b;
        this->w=w;
    }
};
bool cmp(wifi a,wifi b)
{
    return a.w<b.w;
}
int main()
{
    ll n,e;
    cin>>n>>e;
    dsu_inlz(n);
    vector<wifi>el;
    while(e--)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        el.push_back(wifi(a,b,w));
    }
    sort(el.begin(),el.end(),cmp);
    ll tc=0;
    for(wifi ed:el)
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
        }
    }
   

    ll root=dsu_find(1);
    for(ll i=2;i<=n;i++)
    {
        if(dsu_find(i)!=root)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<tc<<endl;
    return 0;
}











// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// const int N=1e5+5;
// int par[N];
// int gs[N];
// void dsu_inlz(ll n)
// {
//     for(int i=0;i<n;i++)
//     {
//         par[i]=-1;
//         gs[i]=1;
//     }
// }
// int dsu_find(ll node)
// {
//     if(par[node]==-1)
//     {
//         return node;
//     }
//     ll l=dsu_find(par[node]);
//     par[node]=l;
//     return l;
// }
// void dus_union_size(ll n1,ll n2)
// {
//     ll lA=dsu_find(n1);
//     ll lB=dsu_find(n2);
//     if(gs[lA]>gs[lB])
//     {
//         par[lB]=lA;
//         gs[lA]+=gs[lB];
//     }
//     else
//     {
//         par[lA]=lB;
//         gs[lB]+=gs[lA];
//     }
// }
// class wifi
// {
//     public:
//     ll a,b,w;
//     wifi(ll a,ll b,ll w)
//     {
//         this->a=a;
//         this->b=b;
//         this->w=w;
//     }
// };
// bool cmp(wifi a,wifi b)
// {
//     return a.w<b.w;
// }
// int main()
// {
//     ll n,e;
//     cin>>n>>e;
//     dsu_inlz(n);
//     vector<wifi>el;
//     while(e--)
//     {
//         ll a,b,w;
//         cin>>a>>b>>w;
//         el.push_back(wifi(a,b,w));
//     }
//     sort(el.begin(),el.end(),cmp);
//     int tc=0;
//     int connected_components = n; // Initially, each building is its own connected component
//     for(wifi ed:el)
//     {
//         int lA=dsu_find(ed.a);
//         int lB=dsu_find(ed.b);
//         if(lB==lA)
//         {
//             continue;
//         }
//         else
//         {
//             dus_union_size(ed.a,ed.b);
//             tc+=ed.w;
//             connected_components--; // Merge the components
//             if (connected_components == 1) // If all buildings are connected, break the loop
//                 break;
//         }
//     }
//     if (connected_components != 1) // If there are more than one connected components, print -1
//         cout << -1 << endl;
//     else
//         cout<<tc<<endl;
// }
