//https://leetcode.com/problems/find-the-difference/
//389. Find the Difference
class Solution {
public:
    char findTheDifference(string s, string t) {
        int xo = 0, i;
        for(i = 0; i < s.size() ; ++i) xo ^= s[i]^t[i];
        return xo^=t[i];
    }
};