class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        parent[find(a)] = find(b);
    }

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        parent.resize(n);

        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(stones[i][0]==stones[j][0] ||
                   stones[i][1]==stones[j][1])
                    unite(i,j);
            }
        }

        set<int> components;

        for(int i=0;i<n;i++)
            components.insert(find(i));

        return n - components.size();
    }
};