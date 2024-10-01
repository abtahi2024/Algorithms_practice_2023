#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char mz[N][N];
// char a[N][N];
bool vt[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    vt[src.first][src.second] = true;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 4; i++)
        {
            int nw_x = x + dx[i];
            int nw_y = y + dy[i];
            if (valid(nw_x, nw_y) && !vt[nw_x][nw_y] && mz[nw_x][nw_y] != '#')
            {
                q.push({nw_x, nw_y});
                vt[nw_x][nw_y] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    pair<int, int> src, det;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mz[i][j];
            if (mz[i][j] == 'A')
                src = {i, j};
            if (mz[i][j] == 'B')
                det = {i, j};
        }
    }
    memset(vt,false,sizeof(vt));
    bfs(src);
    if (vt[det.first][det.second] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
