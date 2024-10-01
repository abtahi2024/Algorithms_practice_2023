#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dis[5005];
vector<pair<ll, ll>> v[5005];
ll par[5005];
class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};
void dikjstra(int s)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    // par[s]=-1;
    while (!pq.empty())
    {
        pair<ll, ll> prt = pq.top();
        pq.pop();
        ll node = prt.first;
        ll cost = prt.second;
        for (pair<ll, ll> child : v[node])
        {
            ll childnode = child.first;
            ll childcost = child.second;
            if (cost + childcost < dis[childnode])
            {
                dis[childnode] = cost + childcost;
                pq.push({childnode, dis[childnode]});
                par[childnode] = node;
            }
        }
    }
}
int main()
{
    ll n, m, s, f;
    cin >> n >> m >> s >> f;
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
        par[i] = -1;
    }

    dikjstra(s);
    if (dis[f] == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[f] << endl;
        ll x = f;
        vector<ll> path;
        while (x != -1)
        {
            path.push_back(x);
            x = par[x];
        }
        reverse(path.begin(), path.end());
        for (ll val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
