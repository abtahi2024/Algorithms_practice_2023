#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,e;
    cin>>n>>e;
    ll adj[n+1][n+1];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
           adj[i][j]=1e16;
            if(i==j)
            {
                adj[i][j]=0;
            }
            // else
            // {
            //     adj[i][j]=1e18;
            // }
        }
    }
    while (e--)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        // adj[a][b]=min(adj[a][b],w);
        if(adj[a][b]>w)
        {
            adj[a][b]=w;
        }
      
    }

    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    ll q;
    cin>>q;
    for(ll i=1;i<=q;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(adj[x][y]==1e16)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<adj[x][y]<<endl;
        }
    }

    return 0;
}




