//https://leetcode.com/problems/number-complement/
//476. Number Complement
class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0;
        while(num){
            if((num & (1<<i)) == 0) ans |= (1<< i);
            else num ^= (1<<i);
            i++;
        }
        return ans;
    }
};