//https://leetcode.com/problems/coin-change/
//322. Coin Change
class Solution {
public:
    int memo[1005][10005];
    const int oo = 0x3f3f3f3f;
    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int ans = dp(coins.size()-1, amount, coins);
        return ans >= oo ? -1 : ans;
    }
    
    int dp(int ind, int amo, vector<int>& coins){
        if(amo < 0 || ind < 0) return oo;
        if(amo == 0) return 0;
        int& ans = memo[ind][amo];
        if(ans != -1) return ans;
        return ans = min(1+dp(ind,amo-coins[ind], coins), dp(ind-1, amo, coins));
    }
};