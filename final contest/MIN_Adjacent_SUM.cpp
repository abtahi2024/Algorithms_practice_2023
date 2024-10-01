// #include<bits/stdc++.h>
// using namespace std;

// class cmp
// {
//     public:
//     bool operator()(int a,int b)
//     {
//         return a>b;
//     }
// };
// int main()
// {
//     int n;
//     cin>>n;
    
//     priority_queue<int ,vector<int>,cmp>pq;
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         pq.push(x);
//     }
//     int sum=pq.top();
//     pq.pop();
//     sum+=pq.top();
//     cout<<sum;
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, ans = 0;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0;i < n;i++) {
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     ans = (a[0] + a[1]);
//     cout << ans << '\n';

//     return 0;
// }
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=(a[0]+a[1]);
    }
    cout<<sum<<endl;



    return 0;
}


