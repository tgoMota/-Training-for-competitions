//https://leetcode.com/contest/weekly-contest-183/problems/minimum-subsequence-in-non-increasing-order/
//1403. Minimum Subsequence in Non-Increasing Order
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size() ;  ++i) sum+=nums[i];
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans;
        int sum2 = 0;
        for(int x : nums){
            sum2+=x;
            sum-=x;
            ans.push_back(x);
            if(sum2 > sum) break;
        }
        return ans;
    }
};