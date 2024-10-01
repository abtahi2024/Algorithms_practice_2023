#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string S;
        cin>>S;
        
        
        int o=0,c=0;
        for(char ch: S)
        {
            if(ch== '(')
            {
                o++;
            }
            else
            {
                c++;
            }
        }
        if(o==c&&n%2==0)
        {
            cout<<"Possible"<<endl;
        }
        else
        {
            cout<<"Impossible"<<endl;
        }
        
    }
    
    return 0;
}