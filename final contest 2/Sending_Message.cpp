
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string w1,w2;
    while(cin>>w1>>w2)
    {
       int i=0,j=0;
       bool ans=true;
       while(i<w1.size()&&j<w2.size())
       {
        if(w1[i]==w2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
       }
       if(j<w2.size())
       {
        ans=false;
       }
       if(ans)
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



