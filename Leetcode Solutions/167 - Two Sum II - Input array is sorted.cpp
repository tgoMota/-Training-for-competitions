//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//167. Two Sum II - Input array is sorted
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        for(int i = 0; i < sz ; ++i){
            int hi = sz-1, lo = i+1, mid, ans;
            while(lo <= hi){
                mid = (lo+hi) >> 1;
                if(target-numbers[i] == numbers[mid]) return {i+1,mid+1};
                if(numbers[mid] < target-numbers[i]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return {};
    }
};
int main(){
    int n, t, el;
    cin >> n >> t;
    vector<int> nums, ans;
    for(int i = 0; i < n ; ++i){
        cin >> el;
        nums.push_back(el);
    }
    Solution a;
    ans = a.twoSum(nums, t);
    for(int i = 0; i < ans.size() ; ++i) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}