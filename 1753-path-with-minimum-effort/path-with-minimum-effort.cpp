#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        diff[0][0] = 0;

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        pq.push({0,{0,0}});

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            int effort = cur.first;
            int r = cur.second.first;
            int c = cur.second.second;
            if(effort > diff[r][c]) continue;

            if(r==m-1 && c==n-1) return effort;

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int newEffort = max(
                        effort,
                        abs(heights[r][c] - heights[nr][nc])
                    );

                    if(newEffort < diff[nr][nc]){
                        diff[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};