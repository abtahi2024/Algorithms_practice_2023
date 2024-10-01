#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        int p = 0;
        ll l = 0;
        for (int i = 1; i < n - 1; i++) {
            l += a[i - 1];
            if (l == sum - l - a[i] && i != 0 && i != n - 1)
                p++;
        }
        cout << p << endl;
    }
    return 0;
}
