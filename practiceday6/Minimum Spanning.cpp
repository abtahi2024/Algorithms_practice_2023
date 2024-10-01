
#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int u, v, w;
        Edge(int u, int v, int w) {
            this->u = u;
            this->v = v;
            this->w = w;
        }
    };
    
    bool cmp(Edge a, Edge b) {
        return a.w < b.w;
    }
class Solution {
public:
    int par[1005];
    int g_s[1005];
    
    void dsu_intilize(int n) {
        for(int i = 1; i <= n; i++) {
            par[i] = -1;
            g_s[i] = 1;
        }
    }
    
    int dsu_find(int node) {
        if(par[node] == -1) {
            return node;  
        }
        int l = dsu_find(par[node]);
        par[node] = l;
        return l;
    }
    
    void dsu_union_size(int n1, int n2) {
        int lA = dsu_find(n1);
        int lB = dsu_find(n2);
        if(g_s[lA] > g_s[lB]) {
            par[lB] = lA;
            g_s[lA] += g_s[lB];
        } else {
            par[lA] = lB;
            g_s[lB] += g_s[lA];
        }
    }
    
    
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        dsu_intilize(V);
        vector<Edge> el;
        for(int i = 0; i < V; i++) {
            for(vector<int> edge : adj[i]) {
                int v = edge[0];
                int w = edge[1];
                el.push_back(Edge(i, v, w));
            }
        }
        
        sort(el.begin(), el.end(), cmp);
        
        int sum = 0;
        for(Edge ed : el) {
            int lu = dsu_find(ed.u);
            int lv = dsu_find(ed.v);
            if(lu == lv)
                continue;
            else
                dsu_union_size(ed.u, ed.v);
                sum += ed.w;
        }
        
        return sum;
    }
};
int main()
{
  


    return 0;
}