//1347. Minimum Number of Steps to Make Two Strings Anagram
//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
class Solution {
public:
    int minSteps(string s, string t) {
        int mx = s[0];
        vector<int> ms(150,0);
        vector<int> mt(150,0);
        for(auto x : s) ms[(int)x]++;
        for(auto x : t) mt[(int)x]++;
        
        int steps = 0;
        for(int i = 0; i < s.size() ; ++i){
            if(ms[(int)s[i]] > mt[(int)s[i]])steps += ms[(int)s[i]] - mt[(int)s[i]];
            mt[(int)s[i]] = ms[(int)s[i]];
        }
        
        return steps;
    }
};