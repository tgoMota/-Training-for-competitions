//46. Permutations
//https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(nums);
        next_permutation(nums.begin(), nums.end());
        while(ans[0] != nums){
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};