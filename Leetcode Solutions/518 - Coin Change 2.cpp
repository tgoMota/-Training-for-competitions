//https://leetcode.com/problems/coin-change-2/
//518. Coin Change 2
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int N = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int c : coins){
            for(int sum = c ; sum <= amount ; ++sum){
                dp[sum] += dp[sum-c];
            }
        }
        return dp[amount];
    }
};