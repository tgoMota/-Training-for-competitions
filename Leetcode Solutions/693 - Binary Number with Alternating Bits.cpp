//https://leetcode.com/problems/binary-number-with-alternating-bits/
//693. Binary Number with Alternating Bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return (n & (n>>1)) == 0 && (n & (n>>2)) == n>>2;
    }
};