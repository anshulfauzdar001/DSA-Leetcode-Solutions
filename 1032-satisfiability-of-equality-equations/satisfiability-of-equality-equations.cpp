class Solution {
public:

    int find(int node, vector<int>& parent){
        if(parent[node] < 0) return node;
        return parent[node] = find(parent[node], parent);
    }

    void unionSize(int a,int b,vector<int>& parent){
        a=find(a,parent);
        b=find(b,parent);

        if(a==b) return;

        if(parent[a] < parent[b]){
            parent[a]+=parent[b];
            parent[b]=a;
        }else{
            parent[b]+=parent[a];
            parent[a]=b;
        }
    }

    bool equationsPossible(vector<string>& equations) {

        vector<int> parent(26,-1);

        for(auto &e:equations){
            if(e[1]=='='){
                int a = e[0]-'a';
                int b = e[3]-'a';
                unionSize(a,b,parent);
            }
        }

        for(auto &e:equations){
            if(e[1]=='!'){
                int a = e[0]-'a';
                int b = e[3]-'a';

                if(find(a,parent) == find(b,parent))
                    return false;
            }
        }

        return true;
    }
};