#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        map<int,int> mp;
        for(int i = 0; i < sz ; ++i) {
            if(mp.find(target-nums[i])!=mp.end()) return {mp.find(nums[i])->second, i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
int main(){
    int k, t, e;
    vector<int> ans, b;
    cin >> k >> t;
    for(int i = 0; i < k ; ++i){
        cin >> e;
        ans.push_back(e);
    }
    Solution a;
    b = a.twoSum(ans, t);
    for(int i = 0; i < b.size() ; ++i) printf("%d ", b[i]);
    printf("\n");

    return 0;
}