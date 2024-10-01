#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    set<int>e,o;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;cin>>x;
            if(x%2)
            e.insert(x);
            else
            o.insert(x);
        }
        else if(t==2)
        {
            if(!e.empty())
            {
                cout<<*e.begin()<<endl;
                e.erase(e.begin());
            }
            else
            {
                cout<<"empty"<<endl;
            }
        }
        else if(t==3)
        {
            if(!o.empty())
            {
                cout<<*o.begin()<<endl;
                o.erase(o.begin());
            }
            else
            {
                cout<<"empty"<<endl;
            }
        }
    }

    return 0;
}