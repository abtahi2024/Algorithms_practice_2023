#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>m[n];
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        if(m[x].empty())
        {
            cout<<"-1"<<endl;
        }
        else
        {
            sort(m[x].begin(),m[x].end(),greater<int>());
            for(int i:m[x])
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
    }

   return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, e;
//     cin >> n >> e;
//     vector<int> m[n];
    
//     while (e--) 
//     {
//         int a, b;
//         cin >> a >> b;
//         m[a].push_back(b);
//         m[b].push_back(a);
//     }

//     int q;
//     cin >> q;

//     for(int i = 0; i < q; i++) 
//     {
//         int x;
//         cin >> x;
        
//         if(m[x].empty()) 
//         {
//             cout << "-1" << endl;
//         } 
//         else 
//         {
//             sort(m[x].begin(), m[x].end(), greater<int>());
//             for(int i : m[x]) 
//             {
//                 cout << i << " ";
//             }
//             cout << endl;
//         }
//     }

//     return 0;
// }



