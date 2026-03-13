#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n, -1);
    }

    int find(int node) {
        if (parent[node] < 0)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionSize(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (parent[pa] < parent[pb]) {
            parent[pa] += parent[pb];
            parent[pb] = pa;
        } else {
            parent[pb] += parent[pa];
            parent[pa] = pb;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DisjointSet ds(n * n);

        int ans = 0;

        // connect existing islands
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) {

                    int node = r * n + c;

                    if (r + 1 < n && grid[r + 1][c] == 1) {
                        int adj = (r + 1) * n + c;
                        ds.unionSize(node, adj);
                    }

                    if (c + 1 < n && grid[r][c + 1] == 1) {
                        int adj = r * n + (c + 1);
                        ds.unionSize(node, adj);
                    }
                }
            }
        }

        // try flipping every 0
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0) {

                    set<int> s;

                    if (r > 0 && grid[r - 1][c] == 1)
                        s.insert(ds.find((r - 1) * n + c));

                    if (r + 1 < n && grid[r + 1][c] == 1)
                        s.insert(ds.find((r + 1) * n + c));

                    if (c > 0 && grid[r][c - 1] == 1)
                        s.insert(ds.find(r * n + c - 1));

                    if (c + 1 < n && grid[r][c + 1] == 1)
                        s.insert(ds.find(r * n + c + 1));

                    int count = 1;

                    for (auto x : s)
                        count += -ds.parent[x];

                    ans = max(ans, count);
                }
            }
        }

        // case when grid already full of 1s
        if (ans == 0)
            ans = n * n;

        return ans;
    }
};