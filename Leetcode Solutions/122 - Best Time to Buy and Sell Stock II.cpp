//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        for(int i = 1; i < p.size() ; ++i) ans = max(ans,ans+p[i]-p[i-1]);
        return ans;
    }
};