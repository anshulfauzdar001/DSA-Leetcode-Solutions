class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {

        vector<vector<int>> reach(n, vector<int>(n, 0));

        for(auto &e : pre){
            reach[e[0]][e[1]] = 1;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(reach[i][k] && reach[k][j])
                        reach[i][j] = 1;
                }
            }
        }

        vector<bool> ans;
        for(auto &q : queries){
            ans.push_back(reach[q[0]][q[1]]);
        }
        return ans;
    }
};