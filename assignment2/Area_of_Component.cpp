#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
bool vaild(int ci,int cj)
{
    return ci>=0&&ci<n&&cj>=0&&cj<m&&a[ci][cj]!='-';
}
int dfs(int si,int sj)
{
    vis[si][sj]=true;
    int ara=1;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(vaild(ci,cj)&&!vis[ci][cj])
        {
            ara+=dfs(ci,cj);
        }

    }
    return ara;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            
        }
    }
    int cnt =0;
    int m_a=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='.'&&!vis[i][j])
            {
                cnt++;
                m_a=min(m_a,dfs(i,j));
            }
        }
    }
    if(cnt==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<m_a<<endl;
    }
    return 0;
}

