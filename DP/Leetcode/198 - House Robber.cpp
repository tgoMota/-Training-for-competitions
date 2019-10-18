//https://leetcode.com/problems/house-robber/
//198. House Robber
class Solution {
public:
    const int oo = 0x3f3f3f3f;
    int rob(vector<int>& nums) {
        int memo[nums.size()+5];
        memset(memo, -1, sizeof(memo));
        int ans = -oo;
        for(int i = 0; i < nums.size() ; ++i) ans = max(ans,dp(i,nums, memo));
        return (ans <= -oo ? 0 : ans);
    }
    int dp(int N, vector<int>& nums, int* memo){
        if(N <= 1) return nums[N];
        int& ans = memo[N];
        if(ans != -1) return ans;
        ans = -oo;
        for(int i = N-2; i >= 0 ; --i)
            ans = max(ans,dp(i,nums,memo)+nums[N]);
        return ans;
    }
};