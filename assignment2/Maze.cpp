#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
// int dis[N][N];
char g[N][N];
bool vis[N][N];
pair<int, int> parnt[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int ci, int cj) {
    return ci >= 0 && ci < n && cj >= 0 && cj < m && g[ci][cj] != '#';
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    // dis[si][sj]=0;
    while (!q.empty()) {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
             
                parnt[ci][cj] = par;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
           
            if (g[i][j] == 'R') {
                si = i;
                sj = j;
            }
            if (g[i][j] == 'D') {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    // memset(dis, -1, sizeof(dis));
    memset(parnt, -1, sizeof(parnt));
    bfs(si, sj);

    // Mark the shortest path
    int ci=di,cj=dj;
      if(vis[ci][cj])
      {
          while (ci != si || cj != sj) 
        {
           
            pair<int, int>p = parnt[ci][cj];
            ci = p.first;
            cj = p.second;
            if(g[ci][cj]=='.')
            {
                g[ci][cj] = 'X';
                
            }
            
          
        }
      }


    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << g[i][j];
        }
        cout << endl;
    }


    return 0;
}








// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// char g[N][N];
// bool vis[N][N];
// pair<int, int> par[N][N];
// pair<int, int> d[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// int n, m;
// int si, sj, di, dj;

// bool valid(int i, int j)
// {
//     return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '#' && !vis[i][j]);
// }

// void bfs()
// {
//     queue<pair<int, int>> q;
//     q.push({si, sj});
//     vis[si][sj] = true;

//     while (!q.empty())
//     {
//         pair<int, int> parent = q.front();
//         q.pop();

//         int pi = parent.first;
//         int pj = parent.second;
//         // if (pi == di && pj == dj)
//         //     return;

//         for (pair<int, int> child : d)
//         {
//             int ci = pi + child.first;
//             int cj = pj + child.second;
//             if (valid(ci, cj))
//             {
//                 q.push({ci, cj});
//                 vis[ci][cj] = true;
//                 par[ci][cj] = {pi, pj};
//             }
//         }
//     }
// }

// void path(int i, int j)
// {
//     int a = par[i][j].first, b = par[i][j].second;

//     if (a == si && b == sj)
//         return;

//     path(a, b);
//     g[a][b] = 'X';
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             char c;
//             cin >> c;
//             if (c == 'R')
//             {
//                 si = i;
//                 sj = j;
//             }
//             else if (c == 'D')
//             {
//                 di = i;
//                 dj = j;
//             }
//             g[i][j] = c;
//         }
//     }
//     memset(vis, false, sizeof(vis));
//     par[si][sj] = {-1, -1};

//     bfs();
//     if (vis[di][dj])
//         path(di, dj);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << g[i][j];
//         }
//         cout << endl;
//     }

//     return 0;
// }