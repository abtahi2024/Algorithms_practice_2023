// #include<bits/stdc++.h>
// using namespace std;
// bool vis[1005][1005];
// int pA[1005][1005];
// vector<pair<int,int>>d={{0,1},{0,-1},{1,0},{-1,0}};
// int n,m,si,sj,ci,cj;
// bool valid(int ci,int cj)
// {
//     return !vis[ci][cj]&&ci>=0&&ci<n&&cj>=0&&cj<m;
// }
// void bfs(int si,int sj)
// {
//     queue<pair<int,int>>q;
//     q.push({si,sj});
//     vis[si][sj]=true;
//     pA[si][sj]={-1,-1};
//     while (!q.empty())
//     {
//         pair<int,int>p=q.front();
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int ci=p.first+d[i].first;
//             int cj=p.second+d[i].second;
//             if(valid(ci,ci))
//             {
//                 vis[ci][cj]=true;
//                 pA[ci][cj]=pA[p.first][p.second];
//                 q.push({ci,cj});
//             }
//         }
//     }
    
// }
// int main()
// {
//     cin>>n>>m;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             memset(pA,-1,sizeof(pA));
//             char c;
//             cin>>c;
//             if(c=='#')
//             {
//                 vis[i][j]=true;
//             }
//             if(c=='A')
//             {
//                 si=i;
//                 sj=j;
//             }
//             if(c=='B')
//             {
//                 ci=i;
//                 cj=j;
//             }
//         }
//     }
//     bfs(si,sj);
//     if(!vis[ci][cj])
//     {
//         cout<<"NO"<<endl;
//         return 0;
//     }
//     cout<<"YES"<<endl;
//     vector<pair<int,int>>ans;
//     pair<int,int >dest={ci,cj};
//     while (dest.first!=si||dest.second!=sj)
//     {
//         ans.push_back({pA[dest.first][dest.second]});
//         dest.first-=ans.back().first;
//         dest.second-=ans.back().second;
//     }
//     reverse(ans.begin(),ans.end());
//     for(pair<int,int>i:ans)
//     {
//         if(i.first==1&&i.second==0)
//         {
//             cout<<"D";
//         }
//         if(i.first==-1&&i.second==0)
//         {
//             cout<<"U";
//         }
//         if(i.first==0&&i.second==-1)
//         {
//             cout<<"L";
//         }
//         if(i.first==0&&i.second==1)
//         {
//             cout<<"R";
//         }
//     }
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;

bool vis[1005][1005];
int pA[1005][1005];
vector<pair<int,int>> d={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,si,sj,ci,cj;

bool valid(int ci,int cj) {
    return ci >= 0 && ci < n && cj >= 0 && cj < m && !vis[ci][cj];
}

void bfs(int si,int sj) {
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    pA[si][sj] = -1; // Initialize starting point with -1
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int ci = p.first + d[i].first;
            int cj = p.second + d[i].second;
            if(valid(ci,cj)) 
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                pA[ci][cj] = i; // Store the direction to backtrack
                
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c;
            cin >> c;
            if(c == '#') {
                vis[i][j] = true;
            }
            if(c == 'A') {
                si = i;
                sj = j;
            }
            if(c == 'B') {
                ci = i;
                cj = j;
            }
        }
    }
    bfs(si,sj);
    if(!vis[ci][cj]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    
    vector<pair<int,int>> ans;
    pair<int,int> dest = {ci,cj};
    while (dest.first != si || dest.second != sj) {
       ans.push_back({d[pA[dest.first][dest.second]].first, d[pA[dest.first][dest.second]].second});

        int direction = pA[dest.first][dest.second];
        dest.first -= d[direction].first;
        dest.second -= d[direction].second;
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(pair<int,int> i:ans) {
        if(i.first == 1 && i.second == 0) {
            cout << "D";
        }
        if(i.first == -1 && i.second == 0) {
            cout << "U";
        }
        if(i.first == 0 && i.second == -1) {
            cout << "L";
        }
        if(i.first == 0 && i.second == 1) {
            cout << "R";
        }
    }
    cout << endl;
    return 0;
}
