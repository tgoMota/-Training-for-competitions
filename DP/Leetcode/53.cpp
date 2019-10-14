//https://leetcode.com/problems/maximum-subarray/
//53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = 0;
        for(int i = 0; i < nums.size() ; ++i){
            sum += nums[i];
            maxSum = max(maxSum,sum);
            sum = max(sum,0);
        }
        return maxSum;
    }
};