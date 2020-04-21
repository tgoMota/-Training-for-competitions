//https://leetcode.com/problems/house-robber/
//198. House Robber
//DP Top-Down
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
//DP Bottom-UP
class Solution {
public:
    const int oo = 0x3f3f3f3f;
    int rob(vector<int>& nums) {
        const int N = nums.size();
        if(N == 0) return 0;
        vector<vector<int>> dp(N+1, vector<int>(2, 0));
        dp[0][1] = nums[0];
        for(int i = 1; i < N ; ++i){
            for(int j = 0; j < 2 ; ++j){
                if(j == 0) dp[i][j] = max(dp[i-1][0], dp[i-1][1]);
                else dp[i][j] = dp[i-1][0]+nums[i];
            }
        }
        return max(dp[N-1][0], dp[N-1][1]);
    }
};