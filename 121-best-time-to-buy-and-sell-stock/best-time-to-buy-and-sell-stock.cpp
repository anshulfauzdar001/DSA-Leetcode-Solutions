class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxProfit = 0;
        for(int price : prices){
            mini = min(mini , price);
            maxProfit = max(maxProfit , price-mini);
        }
        return maxProfit ;
    }
};
