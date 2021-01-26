//https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
//1737. Change Minimum Characters to Satisfy One of Three Conditions
class Solution {
    const int oo = 0x3f3f3f3f;
    int f(string& a, string& b){ //transform b < a
        int ans = oo;
        for(char i = 'a'; i <= 'y' ; ++i){
            int cnt = 0;
            for(char c : a) cnt += c <= i;
            for(char c : b) cnt += c > i;
            ans = min(ans, cnt);
        }
        return ans;
    }
    
    int toEqual(string& a, string& b){
        int ans = oo;
        for(char i = 'a' ; i <= 'z' ; ++i){
            int cnt = 0;
            for(char c : a) cnt += c != i;
            for(char c : b) cnt += c != i;
            ans = min(ans, cnt);
        }
        return ans;
    }
public:
    int minCharacters(string a, string b) {
        return min({f(a,b), f(b,a), toEqual(a,b)});
    }
};
