class Solution {
public:
    int climbStairs(int n) {
        // if (n == 0 || n == 1) return 1;
        // int p1 = 1, p2 = 1, cur = 0;
        // for (int i = 2; i <= n; ++i) {
        //     cur = p1 + p2;
        //     p1 = p2;
        //     p2 = cur;
        // }
        // return cur;
        if(n==0 || n==1)return 1 ;
        int p1 = 1 , p2 = 1 , cur = 0;
        for(int i = 2 ; i<= n ; i++){
            cur = p1 + p2 ;
            p1 = p2 ;
            p2 = cur ;
        }
        return cur ;
    }
};
