class Solution {
public:
     int bs(vector<int>& nums,int l,int h, int x){
        if(l<h){
            int m= (l+h)/2;
            if(nums[m]==x)
                return m;
            return max( bs(nums,l,m,x), bs(nums,m+1,h,x) );
        }
         
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size(),target);
    }
};