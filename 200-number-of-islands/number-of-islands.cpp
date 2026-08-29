#include <vector>
using namespace std;

class Solution {
public:
    // void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {
    //     int r = grid.size();
    //     int c = grid[0].size();
    //     visited[i][j] = 1;
    //     if (i > 0 && grid[i-1][j] == '1' && !visited[i-1][j])
    //         dfs(i-1, j, grid, visited);
    //     if (i + 1 < r && grid[i+1][j] == '1' && !visited[i+1][j])
    //         dfs(i+1, j, grid, visited);
    //     if (j > 0 && grid[i][j-1] == '1' && !visited[i][j-1])
    //         dfs(i, j-1, grid, visited);
    //     if (j + 1 < c && grid[i][j+1] == '1' && !visited[i][j+1])
    //         dfs(i, j+1, grid, visited);
    // }
    void dfs(int i , int j , vector<vector<char>>&grid , vector<vector<int>>&visited){
        int r = grid.size();
        int c = grid[0].size();
        visited[i][j]=1 ;
        if(i>0 && grid[i-1][j] == '1' && !visited[i-1][j])dfs(i-1 , j , grid , visited);
        if(i+1<r &&grid[i+1][j] == '1' &&!visited[i+1][j])dfs(i+1 , j , grid,visited);
        if(j>0 && grid[i][j-1]=='1'&&!visited[i][j-1])dfs(i,j-1,grid,visited);
        if(j+1<c &&grid[i][j+1]=='1' && !visited[i][j+1])dfs(i , j+1 , grid , visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        // int r = grid.size();
        // int c = grid[0].size();
        // vector<vector<int>> visited(r, vector<int>(c, 0));
        // int count = 0;
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         if (grid[i][j] == '1' && !visited[i][j]) {
        //             dfs(i, j, grid, visited);
        //             count++;
        //         }
        //     }
        // }
        // return count;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
        int count = 0 ;
        for(int i = 0 ; i<r ; i++){
            for(int j = 0 ; j<c ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count ;
    }
};
