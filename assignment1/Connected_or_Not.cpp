#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>m[n];
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int A,B;
        cin>>A>>B;
        bool falg=false;
        for(int i:m[A])
        {
            if(i==B)
            {
                falg=true;
                break;
            }
        }
        if(falg||A==B)
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

