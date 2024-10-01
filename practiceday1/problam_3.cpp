#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,e;
  cin>>n>>e;
  vector<int>m[n];
  while (e--)
  {
    /* code */
    int a,b;
    cin>>a>>b;
    m[a].push_back(b);
    m[b].push_back(a);
  }
  int N;
  cin>>N;
  cout<<N<<" ";
//   for(int i=0;i<m[N].size();i++)
//   {
//     cout<<m[N][i]<<" ";
//   }

  


    return 0;
}


