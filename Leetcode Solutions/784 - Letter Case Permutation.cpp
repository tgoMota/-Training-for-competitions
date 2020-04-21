//https://leetcode.com/problems/letter-case-permutation/
//784. Letter Case Permutation
class Solution {
public:
    vector<string> ans;
    void back(string s, int pos){
        for(; pos < s.size() && !isalpha(s[pos]) ; ++pos);
        if(pos == s.size()){
            ans.push_back(s);
            return;
        }
        back(s, pos+1);
        if(s[pos] - 'A' < 26) s[pos] = tolower(s[pos]);
        else s[pos] = toupper(s[pos]);
        back(s, pos+1);
    }
    
    vector<string> letterCasePermutation(string S) {
        back(S, 0);
        return ans;
    }
};