class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        const int N = s.size();
        vector<int> stars;
        for(int i = 0; i < N ; ++i){
            if(s[i] == '*') stars.push_back(i);
            else if(s[i] == '(') st.push(i);
            else {
                if(!st.empty()) st.pop();
                else if((int)stars.size()) stars.pop_back();
                else return false;
            }
        }
        while(!st.empty() && (int)stars.size()){
            int pos = st.top();
            int posstar = stars.back();
            if(posstar > pos) {
                stars.pop_back();
                st.pop();
            }else return false;
        }
        return (int)st.size() == 0;
    }
};