//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//121. Best Time to Buy and Sell Stock
//DP - 1D RANGE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, minPos = 0;
        for(int i = 1; i < prices.size() ; ++i){
            mx=max(mx,prices[i]-prices[minPos]);
            if(prices[i] - prices[minPos] <= 0) minPos = i;
        }
        return mx;
    }
};
//Alternative
class Solution {
public:
    int maxProfit(vector<int>& p) {
        const int sz = p.size(), oo = 0x3f3f3f3f;
        int minp = oo, maxp = 0;
        for(int i = 0; i < sz ; ++i){
            minp = min(minp, p[i]);
            maxp = max(maxp, p[i]-minp);
        }
        return maxp;
    }
};