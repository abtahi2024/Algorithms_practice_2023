#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool reach(ll c,ll n)
{
    if(c==n)
    {
        return true;
    }
    if(c>n)
    {
        return false;
    }
    return reach(c*10,n)||reach(c*20,n);
}
int main()
{
    ll t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ll n;
        cin>>n;
        if(reach (1,n))
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


