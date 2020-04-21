//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
//1365. How Many Numbers Are Smaller Than the Current Number
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans, cpy;
        cpy = nums;
        sort(cpy.begin(), cpy.end());
        for(int i = 0; i < nums.size() ; ++i){
            int k = upper_bound(cpy.begin(), cpy.end(), nums[i]-1) - cpy.begin();
            ans.push_back(k);
        }
        return ans;
    }
};