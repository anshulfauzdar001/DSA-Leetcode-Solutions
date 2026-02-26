#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        const int INF = 1e7;
        vector<vector<int>> matrix(n, vector<int>(n, INF));

        for(int i=0;i<n;i++){
            matrix[i][i] = 0;
        }
        for(auto &x : edges){
            int a = x[0];
            int b = x[1];
            int w = x[2];
            matrix[a][b] = w;
            matrix[b][a] = w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k] < INF && matrix[k][j] < INF){
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        int minCities = INF;
        int ans = n-1;
        for(int i=n-1;i>=0;i--){
            int count = 0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count < minCities){
                minCities = count;
                ans = i;
            }
        }

        return ans;
    }
};