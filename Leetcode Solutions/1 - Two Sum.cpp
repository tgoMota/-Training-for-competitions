//https://leetcode.com/problems/two-sum/
//1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp, mp2;
        for(int i = 0;i < nums.size() ; ++i){
            if(mp.find(nums[i]) == mp.end()) mp.insert({nums[i], i});
            else mp2.insert({nums[i], i});
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() ; ++i){
            int hi = nums.size()-1, lo = i+1, mid;
            while(lo <= hi){
                mid = (lo+hi) >> 1;
                if(target-nums[i] == nums[mid]){
                    int a = mp[nums[mid]], b = mp[nums[i]];
                    if(a < b) return {a,b};
                    else if(a > b) return {b,a};
                    else {
                        b = mp2[nums[i]];
                        if(a < b) return {a,b};
                        else return {b,a};
                    }
                }
                if(nums[mid] < target-nums[i]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return {};
    }
};