#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
int g_s[N];
void dsu_intialize(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=-1;
        g_s[i]=1;
    }

}
int dsu_find(int v)
{
    if(par[v]== -1)
    {
        return v;
    }
    int l=dsu_find(par[v]);
    par[v]=l;
    return l;
}
void dsu_size(int n1,int n2)
{
    int la=dsu_find(n1);
    int lb=dsu_find(n2);
    if(g_s[la]>g_s[lb])
    {
        par[lb]=la;
        g_s[la]+=g_s[lb];
    }
    else
    {
        par[la]=lb;
        g_s[lb]+=g_s[la];
    }
}
class Edge
{
    public:
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int main()
{
    int n,m;
    cin>>n>>m;
    dsu_intialize(n);
    vector <Edge>el;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        el.push_back(Edge(a,b,c));
    }
    sort(el.begin(),el.end(),cmp);
    int tc=0;
    for(Edge ed:el)
    {
        int lu=dsu_find(ed.u);
        int lv=dsu_find(ed.v);
        if(lu==lv)
        {
            continue;
        }
        else
        {
            dsu_size(ed.u,ed.v);
            tc+=ed.w;
        }
    }
    cout<<tc<<endl;

    return 0;
}