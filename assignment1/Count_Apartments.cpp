#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char a[N][N];
bool vt[N][N];
vector<pair<int ,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
bool valid(int ci,int cj)
{
    if(ci<0||ci>=n||cj<0||cj>=m)
    {
        return false;
    }
    return true;
}
int  dfs(int si,int sj)
{
    vt[si][sj]=true;
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(valid(ci,cj)==true&&vt[ci][cj]==false&&a[ci][cj]=='.')
        {
            cnt+=dfs(ci,cj);
        }
    }
    return cnt;
}
int main()
{
    cin>>n>>m;
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
    cout<<r.size()<<endl;

    return 0;
}


