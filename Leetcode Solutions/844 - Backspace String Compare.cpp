class Solution {
public:
    string backspace(string& s){
        string ans="";
        for(int c : s){
            if(c != '#') ans+=c;
            else if((int)ans.size()>0) ans.pop_back();
        }
        return ans;
    }
    
    bool backspaceCompare(string S, string T) {
        return backspace(S) == backspace(T);
    }
};