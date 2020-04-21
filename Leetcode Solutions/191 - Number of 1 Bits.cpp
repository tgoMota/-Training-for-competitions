//https://leetcode.com/problems/number-of-1-bits/
//191. Number of 1 Bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcountl(n);
    }
};