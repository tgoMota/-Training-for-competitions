class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j;
        for(i = 0, j = 0; i < t.size() ; ++i){
            if(s[j] == t[i]) j++;
            if(j == s.size()) break;
        }
        return j == s.size();
    }
};