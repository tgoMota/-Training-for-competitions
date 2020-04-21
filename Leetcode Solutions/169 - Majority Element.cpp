//https://leetcode.com/problems/majority-element/
//169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int n = nums.size();
        int major = n/2, mx = 0, majorelem;
        unordered_map<int,int> m;
        for(int x : nums){
            int k = ++m[x];
            if(max(mx, k) == k){
                majorelem = x;
                mx = k;
            }
            if(mx > major) break;
        }
        return majorelem;
    }
};