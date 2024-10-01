#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N=10;
const ll M=10;
ll dp[N][M];
int knapsack(ll i,ll j,ll n,ll m,ll a[N][M])
{
    if(i==n&&j==m)
    {
        return a[i][j];
    }
    if(dp[i][j]!= -1)
    {
        return dp[i][j];
    }

    ll d=INT_MIN,r=INT_MIN;
    if(i<n)
        d=knapsack(i+1,j,n,m,a);
        if(j<m)
        r=knapsack(i,j+1,n,m,a);
        return dp[i][j]=a[i][j]+max(d,r);

    
    
    

}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[N][M];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));


    cout<<knapsack(1,1,n,m,a)<<endl;

    return 0;
}



