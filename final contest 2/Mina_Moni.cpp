#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s=0;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        if(s%2==0)
        {
            int sum=s/2;
            bool dp[n+1][sum+1];
            dp[0][0]=true;
            for(int i=1;i<=sum;i++)
            {
                dp[0][i]=false;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<=sum;j++)
                {
                    if(a[i-1]<=j)
                    {
                    dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }

            }
            if(dp[n][sum])
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<dp[n][sum]<<endl;
            }
        }
        else
        {
            int sum=s/2;
            bool dp[n+1][sum+1];
            dp[0][0]=true;
             for(int i=1;i<=sum;i++)
            {
                dp[0][i]=false;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<=s;j++)
                {
                    if(a[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            int ans=INT_MAX;
            for(int j=sum;j>=0;j--)
            {
                if(dp[n][j])
                {
                    ans=min(ans,s-2);
                }
            }
            cout<<ans<<endl;
        }
    }



    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// int minSubsetSumDiff(vector<int>& coins) {
//     int totalSum = 0;
//     for(int coin : coins) {
//         totalSum += coin;
//     }

//     int n = coins.size();
//     vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));
    
//     for(int i = 0; i <= n; i++) {
//         dp[i][0] = true;
//     }

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= totalSum; j++) {
//             if(coins[i - 1] <= j) {
//                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - coins[i - 1]];
//             } else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     int minDiff = INT_MAX;
//     for(int j = totalSum / 2; j >= 0; j--) {
//         if(dp[n][j]) {
//             minDiff = totalSum - 2 * j;
//             break;
//         }
//     }

//     return minDiff;
// }

// int main() {
//     int t;
//     cin >> t;

//     while(t--) {
//         int n;
//         cin >> n;
//         vector<int> coins(n);
//         for(int i = 0; i < n; i++) {
//             cin >> coins[i];
//         }
//         cout << minSubsetSumDiff(coins) << endl;
//     }

//     return 0;
// }
