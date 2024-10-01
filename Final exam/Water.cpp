#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>h(n);
        for(ll i=0;i<n;i++)
        {
            cin>>h[i];
        }
        ll ans=INT_MIN;
        ll ai= -1,aj= -1;
        ll i=0, j=n-1;
        while(i<j)
        {
            if(min(h[i],h[j])>ans)
            {
                ans=min(h[i],h[j]);
                ai=i;
                aj=j;
            }
            if(h[i]<h[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        cout<<ai<<" "<<aj<<endl;
    }
  


    return 0;
}





// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> h(n);
//         for(int i = 0; i < n; i++) {
//             cin >> h[i];
//         }
        
//         int left = 0, right = n - 1;
//         long long maxArea = 0;
//         int leftIndex = 0, rightIndex = 0;
        
//         while (left < right) {
//             long long area = min(h[left], h[right]) - (right + left);
//             if (area > maxArea) {
//                 maxArea = area;
//                 leftIndex = left;
//                 rightIndex = right;
//             }
//             if (h[left] < h[right])
//                 left++;
//             else
//                 right--;
//         }
        
//         cout << leftIndex << " " << rightIndex << endl;
//     }

//     return 0;
// }

