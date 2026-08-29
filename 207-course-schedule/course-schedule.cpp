class Solution {
public:
    bool dfs(int node , vector<vector<int>>&adj , vector<int>&visited , vector<int>&path){
        visited[node] = 1 ;
        path[node] = 1 ;
        for(int next : adj[node]){
            if(!visited[next]){
                if(dfs(next,adj,visited,path))return true ;
            }else if(path[next]){
                return true ;
            }
        }
        path[node] = 0 ;
        return false ;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(auto &p : prerequisites)adj[p[1]].push_back(p[0]);
        vector<int> visited(n,0) , path(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path))return false;
            }
        }
        return true;
    }
};
