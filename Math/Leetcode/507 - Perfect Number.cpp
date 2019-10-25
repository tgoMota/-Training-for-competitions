//https://leetcode.com/problems/perfect-number/
//507. Perfect Number
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(!num) return false;
        int sum = 0;
        for(int i = 1; i <= num/2 ; ++i)
            if(num % i == 0) sum+=i;
        return sum == num;
    }
};