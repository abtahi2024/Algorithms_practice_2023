// #include <bits/stdc++.h>
// using namespace std;
// bool vis[50][50];
// // int dis[50][50];
// pair<int, int> part[50][50];
// vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// int n;
// char g[50][50];
// bool valid(int ci, int cj)
// {
//     return ci>=1&&ci<=n&&cj>=1&&cj<=n&&g[ci][cj]!='O';
// }

// void bfs(int si, int sj)
// {
//     queue<pair<int, int>> q;
//     q.push({si, sj});
//     vis[si][sj] = true;
//     // dis[si][sj] = 0;
//     while (!q.empty())
//     {
//         pair<int, int> par = q.front();
//         int a = par.first, b = par.second;
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int ci = a + d[i].first;
//             int cj = b + d[i].second;
//             if (valid(ci, cj)  && !vis[ci][cj])
//             {
//                 q.push({ci, cj});
//                 vis[ci][cj] = true;
//                 part[ci][cj]=par;
//             }
//         }
//     }
// }
// int main()
// {
//     cin>>n;
//     int si,sj,di,dj;

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin>>g[i][j];
//             if(g[i][j]=='@')
//             {
//                 si=i;
//                 sj=j;
//             }
//             if(g[i][j]=='X')
//             {
//                 di=i;
//                 dj=j;
//             }
//         }
//     }
//     memset(vis,false,sizeof(vis));
//     // memset(dis,-1,sizeof(dis));
//     memset(part,-1,sizeof(part));
//     bfs(si,sj);
//     if(vis[di][dj])
//     {
//         cout<<"Y";
//         while(part[di][dj].first!=-1&&part[di][dj].second!=-1)
//         {
//             g[di][dj]='+';
//             pair<int,int>s=part[di][dj];
//             di=s.first;
//             dj=s.second;
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout<<g[i][j];
//             }
//             cout<<endl;
//         }
        
        
        
//     }
//     else
//     {
//         cout<<"N"<<endl;
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

const int N = 41;
char adj[N][N];
bool vis[N][N];
pair<int, int> par[N][N];
int n;
vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && adj[i][j] != 'O';
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;
            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                par[ci][cj] = {parent.first, parent.second};
            }
        }
    }
}

int main()
{
    cin >> n;
    int si, sj;
    int di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            adj[i][j] = x;
            par[i][j] = {-1, -1};
            if (x == '@')
            {
                si = i;
                sj = j;
            }
            if (x == 'X')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);

    if (vis[di][dj])
    {
        cout << "Y" << endl;

        while(par[di][dj].first!=-1 && par[di][dj].second!=-1){
            adj[di][dj] = '+';
            pair<int, int> s = par[di][dj];
            di = s.first;
            dj = s.second;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}
