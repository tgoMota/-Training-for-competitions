//https://leetcode.com/problems/min-cost-climbing-stairs/
//746. Min Cost Climbing Stairs

class Solution {
public:
    const int oo = 0x3f3f3f3f;
    int memo[1005];
    int dp(int ind, int top, vector<int>& cost){
        if(ind >= top) return 0;
        if(ind == top-1) return cost[ind];
        int& ans = memo[ind];
        if(ans != -1) return ans;
        return ans = min(dp(ind+1, top, cost)+cost[ind], dp(ind+2,top,cost)+cost[ind]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        memset(memo, -1, sizeof(memo));
        return min(dp(0, N, cost), dp(1, N, cost));
    }
};