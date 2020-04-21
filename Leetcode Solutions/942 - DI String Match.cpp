//https://leetcode.com/problems/di-string-match/
//942. DI String Match
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int maxp = s.size(), minp = 0;
        vector<int> ans;
        for(int i = 0; i < s.size() ; ++i){
            if(s[i] == 'I') ans.push_back(minp++);
            else ans.push_back(maxp--);
        }
        ans.push_back(minp);
        return ans;
    }
};