#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
int group_size[N];
void dus_inlz(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        group_size[i]=1;
    }
}
int dus_find(int node)
{
    if(par[node]==-1)
    return node;
    int lend=dus_find(par[node]);
    par[node]=lend;
    return lend;
}
void dsu_union(int n1,int n2)
{
    int leaderA=dus_find(n1);
    int leaderB=dus_find(n2);
    if(leaderA!=leaderB)
    {
        if(group_size[leaderA]<group_size[leaderB])
        {
            swap(leaderA,leaderB);
        }
        par[leaderB]=leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
   
}

int main()
{
    int n,m;
    cin>>n>>m;
    dus_inlz(n);
    vector<pair<int,int>>ad;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    
    bool all=true;
    for(int i=2;i<=n;i++)
    {
        if(dus_find(1)!=dus_find(i))
        all=false;
        break;
    }
   
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(par[i]==-1)
        {
            c++;
        }
    }
    int r=c-1;
    cout<<r<<endl;
    for(int i=1;i<n;i++)
    {
        if(dus_find(i)!=dus_find(i+1))
        ad.push_back({i,i+1});
        dsu_union(i,i+1);
    }
  
    for(pair<int,int >ar:ad)
    {
        cout<<ar.first<<" "<<ar.second<<endl;
    }
   
    return 0;
}



