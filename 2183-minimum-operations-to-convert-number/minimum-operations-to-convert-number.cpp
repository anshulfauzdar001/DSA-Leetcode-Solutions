#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {

        if(start == goal) return 0;

        vector<int> dist(1001, INT_MAX);
        queue<pair<int,int>> q;

        if(start >= 0 && start <= 1000)
            dist[start] = 0;

        q.push({start,0});

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            int num = x.first;
            int count = x.second;

            for(auto k : nums){

                vector<int> next = {num + k, num - k, num ^ k};

                for(int neighbour : next){

                    if(neighbour == goal)
                        return count + 1;

                    if(neighbour >= 0 && neighbour <= 1000 &&
                       count + 1 < dist[neighbour]){

                        dist[neighbour] = count + 1;
                        q.push({neighbour, dist[neighbour]});
                    }
                }
            }
        }
        return -1;
    }
};