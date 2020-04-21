//https://leetcode.com/problems/longest-increasing-subsequence/
//300. Longest Increasing Subsequence
class Solution {
public:
    const int oo = 0x3f3f3f3f;
    int lengthOfLIS(vector<int>& nums) {
        const int sz = nums.size();
        vector<int> aux(sz+1, oo);
        aux[0] = -oo;
        for(int i = 0; i < sz ; ++i){
            int j = upper_bound(aux.begin(), aux.end(), nums[i]) - aux.begin();
            if(aux[j-1] <  nums[i] && aux[j] > nums[i]) aux[j] = nums[i];
        }
        int ans = 0;
        for(int i = 0; i <= sz ; ++i)
            if(aux[i] < oo) ans = i;
        return ans; 
    }
};