//https://leetcode.com/problems/split-a-string-in-balanced-strings/
//1221. Split a String in Balanced Strings
class Solution {
public:
    int balancedStringSplit(string s) {
        int mix = 0, ans = 0;
        for(char c : s){
            if(c == 'R') mix++;
            else mix--;
            if(mix == 0) ans++;
        }
        return ans;
    }
};