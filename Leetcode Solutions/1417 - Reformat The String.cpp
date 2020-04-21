class Solution {
public:
    string reformat(string s) {
        int l = 0, n = 0;
        const int N = s.size();
        stack<char> la, na;
        for(char c : s){
            if(isalpha(c)){
                la.push(c);
                l++;
            }
            else{
                n++;
                na.push(c);
            }
        }
       
        if(abs(l-n) > 1) return "";
        string ans = "";
        if(l < n){
            ans += na.top();
            na.pop();
        }
        while(!la.empty() || !na.empty()){
            if(!la.empty()) {
                ans+= la.top();
                la.pop();
            }
            if(!na.empty()) {
                ans+= na.top();
                na.pop();
            }
        }
        return ans;
    }
};