//https://leetcode.com/problems/missing-number/
//268. Missing Number
class Solution {
public://PA
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sn = (n*(n+1))/2, sum = 0;
        for(int x : nums) sum+=x;
        return sn - sum;
    }
};