//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
//1295. Find Numbers with Even Number of Digits
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            int sz = to_string(x).size();
            ans+= sz % 2 == 0;
        }
        return ans;
    }
};