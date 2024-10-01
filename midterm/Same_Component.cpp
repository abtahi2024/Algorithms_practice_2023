#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m||a[i][j]=='-')
        return false;
    return true;
}
void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int di = si + d[i].first;
        int dj = sj + d[i].second;
        if (valid(di, dj) == true && vis[di][dj] == false)
        {
            dfs(di, dj);
        }
    }
}
int main()
{
    // int n,e;
    cin>>n>>m;
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    dfs(si,sj);
    if(vis[di][dj])
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;


}

