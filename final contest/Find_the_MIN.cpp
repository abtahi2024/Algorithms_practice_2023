#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(int a, int b)
    {
        return (a > b);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;
    vector<int> v;
    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int x;
            cin >> x;
            if (v.empty())
            {
                v.push_back(x);
                pq.push(x);
            }
            else
            {
                auto it = find(v.begin(), v.end(),x);
                if (it == v.end())
                {
                    v.push_back(x);
                    pq.push(x);
                }
            }
        }
        else if (c== 2)
        {
            if (pq.empty())
            {
                cout << "empty\n";
            }
            else
            {
                cout << pq.top() << "\n";
                auto it = find(v.begin(), v.end(),pq.top());
                if (it != v.end())
                {
                    v.erase(it);
                }
                pq.pop();
            }
        }
    }

    return 0;
}