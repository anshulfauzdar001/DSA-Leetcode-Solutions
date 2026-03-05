#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find(int node, vector<int>& parent){
        if(parent[node] < 0) return node;
        return parent[node] = find(parent[node], parent);
    }

    void unionSize(int a,int b,vector<int>& parent){
        a = find(a,parent);
        b = find(b,parent);

        if(a==b) return;

        if(parent[a] < parent[b]){
            parent[a] += parent[b];
            parent[b] = a;
        }else{
            parent[b] += parent[a];
            parent[a] = b;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<int> parent(n+1,-1);

        for(auto &e:edges){
            int u = e[0];
            int v = e[1];

            if(find(u,parent) == find(v,parent))
                return e;

            unionSize(u,v,parent);
        }

        return {};
    }
};