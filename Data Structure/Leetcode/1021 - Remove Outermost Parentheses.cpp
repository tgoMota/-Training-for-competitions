//1021. Remove Outermost Parentheses
//https://leetcode.com/problems/remove-outermost-parentheses/
class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i < S.size() ; ++i){
            if(S[i] == '(') {
                st.push('(');
                if(st.size()>1) ans+='(';
            }
            else if(S[i] == ')'){
                if(st.size()>1) ans+=")";
                st.pop();
            }
        }
        return ans;
    }
};