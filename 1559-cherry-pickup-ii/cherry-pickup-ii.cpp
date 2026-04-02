class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> front(n, vector<int>(n, 0));
        vector<vector<int>> curr(n, vector<int>(n, 0));

        // Base case: last row
        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = 0; c2 < n; c2++) {
                if (c1 == c2)
                    front[c1][c2] = grid[m-1][c1];
                else
                    front[c1][c2] = grid[m-1][c1] + grid[m-1][c2];
            }
        }

        // Fill DP from bottom to top
        for (int row = m - 2; row >= 0; row--) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int c2 = 0; c2 < n; c2++) {

                    int maxi = 0;

                    // Try all 9 moves
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {

                            int newC1 = c1 + d1;
                            int newC2 = c2 + d2;

                            if (newC1 >= 0 && newC1 < n &&
                                newC2 >= 0 && newC2 < n) {

                                int value = 0;

                                // Collect cherries
                                if (c1 == c2)
                                    value = grid[row][c1];
                                else
                                    value = grid[row][c1] + grid[row][c2];

                                value += front[newC1][newC2];

                                maxi = max(maxi, value);
                            }
                        }
                    }

                    curr[c1][c2] = maxi;
                }
            }

            front = curr;
        }

        return front[0][n-1];
    }
};