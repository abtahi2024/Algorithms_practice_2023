#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int dis[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dis[i][j];
         
            if(dis[i][j]== -1)
            {
                dis[i][j]=INT_MAX;
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i][k]!=INT_MAX&&dis[k][j]!=INT_MAX&&dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }

        }
    }
  int mx=INT_MIN;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
        if(dis[i][j]!=INT_MAX&&dis[i][j]>mx)
        {
            mx=dis[i][j];
        }
    }
  }
  cout<<mx<<endl;

    return 0;
}


