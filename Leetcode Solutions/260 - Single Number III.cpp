//https://leetcode.com/problems/single-number-iii/
//260. Single Number III
class Solution {
public:
    vector<int> singleNumber(vector<int>& num) {
        int ans = 0;
        for(int i = 0; i < num.size() ; ++i) ans^=num[i];
        int a = 0, b = 0, mask = 1;
        while((mask & ans) == 0) mask = mask<<1;
        for(int i = 0; i < num.size() ; ++i){
            if((num[i] & mask) == 0) a^=num[i];
            else b^=num[i];
        }
        return {a,b};
    }
};