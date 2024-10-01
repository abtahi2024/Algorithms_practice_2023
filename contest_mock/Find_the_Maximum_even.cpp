#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int >a(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==0&&a[i]>ans)
        {
            ans=a[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((a[i]+a[j])%2==0&&a[i]+a[j]>ans)
            {
                ans=a[i]+a[j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}