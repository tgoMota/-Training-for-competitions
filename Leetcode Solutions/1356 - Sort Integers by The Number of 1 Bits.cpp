//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
//1356. Sort Integers by The Number of 1 Bits
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int& a, int& b){
            int na = __builtin_popcount(a), nb = __builtin_popcount(b);
            return na == nb ? a<b : na<nb;
        });
        return arr;
    }
};