class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        // int maxCount = 0, rowIndex = 0;
        // for (int i = 0; i < mat.size(); ++i) {
        //     int count = 0;
        //     for (int val : mat[i]) {
        //         count += val;
        //     }
        //     if (count > maxCount) {
        //         maxCount = count;
        //         rowIndex = i;
        //     }
        // }
        // return {rowIndex, maxCount};
        int maxCount = 0 ;
        int rowIndex = 0 ;
        for(int i = 0 ; i<mat.size() ; i++){
            int count = 0 ;
            for(int val : mat[i]){
                count += val ;
            }
            if(count > maxCount){
                maxCount = count;
                rowIndex = i;
            }
        }
        return{rowIndex , maxCount};
    }
};
