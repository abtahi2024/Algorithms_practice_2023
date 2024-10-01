#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int dp[n + 1][s + 1];
        // memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=0;
        }
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                dp[i][j] = dp[i - 1][j];

                int leftSum = j - a[i - 1];
                if (leftSum >= 0) {
                    dp[i][j] += dp[i][leftSum];
                    dp[i][j] %= mod;
                }
            }
        }

        cout << dp[n][s] << endl;
    }

    return 0;
}
