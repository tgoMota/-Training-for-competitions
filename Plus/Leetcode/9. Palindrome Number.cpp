//9. Palindrome Number
//https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x % 10 == 0 || x < 0) return false;
        int eq = x, pot = 0;
        while(eq != 0){
            eq/=10;
            pot++;
        }
        return reverseNumber(x, --pot) == x;
    }
    
    int reverseNumber(int x, int max){
        int k = 0, sum = 0;
        while(x != 0){
            sum += (x % 10) * (pow(10,max));
            x /= 10;
            max--;
        }
        return sum;
    }
};