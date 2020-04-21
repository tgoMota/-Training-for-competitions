//https://leetcode.com/problems/reverse-bits/
//190. Reverse Bits
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, pos = 0, end = 31;
        while(pos < 32){
            if((n & (1<<end))) ans |= (1<<pos);
            end--; pos++;
        }
        return ans;
    }
};