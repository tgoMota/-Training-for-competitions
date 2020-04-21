//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
//921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        int ans = 0;
        for(char c : S){
            if(c == '(') s.push(c);
            else{
                if(!s.empty()) s.pop();
                else ans++;
            }
        }
        int plus = (int) s.size() > 0 ? s.size() : 0;
        return ans+plus;
    }
};