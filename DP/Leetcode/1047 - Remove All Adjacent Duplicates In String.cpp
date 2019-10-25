//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
//1047. Remove All Adjacent Duplicates In String
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i < S.size() ; ++i){
            if(!st.empty() && st.top() == S[i]) st.pop();
            else st.push(S[i]);
        }
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};