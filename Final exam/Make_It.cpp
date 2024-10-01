#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
const int N=1e5+5;
int dp[N];
bool make_it(ll n,ll tar)
{
    if(n==tar)
    {
        return true;
    }
    if(n>tar)
    {
        return false;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    bool ans1=make_it(n+3,tar);
    bool ans2=make_it(n*2,tar);
    return dp[n]=ans1||ans2;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        if(make_it(1,n))
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