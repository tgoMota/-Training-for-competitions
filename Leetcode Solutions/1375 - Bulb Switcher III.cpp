//https://leetcode.com/problems/bulb-switcher-iii/
//1375. Bulb Switcher III
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        int ans = 0, mx = 0;
        for(int m = 0; m < n ; ++m){
            mx = max(mx, light[m]);
            if(mx == m+1) ans++;
        }
        return ans;
    }
};