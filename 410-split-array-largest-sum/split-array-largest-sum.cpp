class Solution {
public:
    int countstudents(vector<int> &nums , int idx){
        int n = nums.size();
        int students =1 ;
        long long pages = 0 ;
        for(int i = 0 ; i<n ;i++){
            if(pages+nums[i] <= idx){
                pages+=nums[i];
            }
            else{
                students++ ;
                pages= nums[i];
            }
        }
        return students ;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n)return -1 ;
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);
        while(low<=high){
            int mid = low+(high-low)/2 ;
            if(countstudents(nums,mid) > k)low=mid+1 ;
            else high = mid-1 ;
        }
        return low ;
    }
};