// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;
// int main()
// {
//     ll n,h;
//     cin>>n>>h;
//     vector<ll> a(n);
//      ll da=1;
//     for(ll i=0;i<n;i++)
//     {
//         cin>>a[i];
//         da-=a[i];
//         int g=h-da;
//         if(g<0)
//         {
//             cout<<"Hable"<<endl;
//             return 0;
//         }
//         if(h>g)
//         {
//             cout<<"Dablu"<<endl;
//             return 0;
//         }

//     }
//     cout<<"Hablu"<<endl;
//     // ll ha=0;
//     // for(ll i=0;i<n;i++)
//     // {
//     //     da-=a[i];
//     //     // ha=max(ha,a[i]);
//     //     ll g=h-da;
//     //     if(g<=0)
//     //     {
//     //         cout<<"Hablu"<<endl;
//     //         return 0;
//     //     }
//     //     if(h>=g)
//     //     {
//     //         cout<<"Dablu"<<endl;
//     //         return 0;
//     //     }
//     // }
//     // cout<<"Hablu"<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n, h;
    cin >> n >> h;
    int ma=INT_MIN;
    for (ll i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(ma<x)
        {
            ma=x;
        }
    }
    int wi=-1;
    while (true)
    {
        ma--;
        h-=ma;
        if(h<1)
        {
            wi=0;
            break;
        }
        if(ma==0)
        {
            wi=1;
            break;
        }
    }
    if(wi)
    {
        cout<<"Hablu"<<endl;
    }
    else
    {
        cout<<"Dablu"<<endl;
    }
 



    return 0;
}
