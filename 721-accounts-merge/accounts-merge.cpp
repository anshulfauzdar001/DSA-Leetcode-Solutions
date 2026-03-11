#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    class DisjointSet {
    public:
        vector<int> parent;

        DisjointSet(int n) {
            parent.resize(n, -1);
        }

        int find(int node) {
            if(parent[node] < 0) return node;
            return parent[node] = find(parent[node]);
        }

        void unionSize(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return;

            if(parent[pa] < parent[pb]) {
                parent[pa] += parent[pb];
                parent[pb] = pa;
            }
            else {
                parent[pb] += parent[pa];
                parent[pa] = pb;
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int> emailMap;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if(emailMap.find(email) == emailMap.end()) {
                    emailMap[email] = i;
                }
                else {
                    ds.unionSize(i, emailMap[email]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for(auto &it : emailMap) {
            string email = it.first;
            int node = it.second;

            int parent = ds.find(node);
            merged[parent].push_back(email);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(merged[i].size() == 0) continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &email : merged[i])
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};