//https://leetcode.com/problems/move-zeroes/
//283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size()-cnt ;){
            if(nums[i] == 0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                cnt++;
                continue;
            }
            i++;
        }
    }
};