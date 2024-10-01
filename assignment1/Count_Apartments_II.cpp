#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char a[N][N];
vector <pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
bool vt[N][N];
int n,m;
bool vald(int ci,int cj)
{
    if(ci<0||ci>=n||cj<0||cj>=m)
    {
        return false;
    }
    return true;
}
int dfs(int si,int sj)
{
    // cout<<si<<" "<<sj<<endl;
    vt[si][sj]=true;
    int cnt=1;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(vald(ci,cj)==true&&vt[ci][cj]==false&&a[ci][cj]=='.')
        {
            cnt+=dfs(ci,cj);
        }
    }
    return cnt;
}
int main()
{ 
    
     cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(vt, false, sizeof(vt));
    vector<int>r;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vt[i][j]&&a[i][j]=='.')
            {
               r.push_back(dfs(i,j));
            }
        }
    }
    sort(r.begin(),r.end());
    for(int c:r)
    {
        cout<<c<<" ";
    }
    if(r.empty())
    {
        cout<<0;
    }
    return 0;
}


