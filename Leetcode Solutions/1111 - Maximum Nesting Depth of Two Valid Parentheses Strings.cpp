class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        const int N = s.size();
        stack<char> st;
        vector<int> ans;
        for(int i = 0; i < N ; ++i){
            if(s[i] == '(')  {
                ans.push_back(((int)st.size())%2);
                st.push(s[i]);
            }else{
                st.pop();
                ans.push_back(((int)st.size())%2);
            }
        }
        return ans;
    }
};