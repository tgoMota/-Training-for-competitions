//https://leetcode.com/problems/climbing-stairs/
//70. Climbing Stairs
class Solution {
public:
    int memo[51];
    const int oo = 0x3f3f3f3f;
    int climbStairs(int n) {
        memset(memo, -1, sizeof(memo));
        return dp(0,n);
    }
    int dp(int ind, const int n){
        if(ind > n) return 0;
        if(ind == n) return 1;
        int& ans = memo[ind];
        if(ans != -1) return ans;
        return ans = dp(ind+1, n) + dp(ind+2, n);
    }
};