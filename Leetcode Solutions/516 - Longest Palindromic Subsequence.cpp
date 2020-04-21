//https://leetcode.com/problems/longest-palindromic-subsequence/
//516. Longest Palindromic Subsequence
class Solution {
public:
    int memo[1005][1005];
    int longestPalindromeSubseq(string s) {
        memset(memo, -1, sizeof(memo));
        return dp(0, s.size()-1,(char*)s.c_str());
    }
    
    int dp(int indi, int indj, char* s){
        if(indi > indj) return 0;
        int& ans = memo[indi][indj];
        if(ans != -1) return ans;
        if(s[indi] == s[indj]) return ans = (indj == indi?1:2)+ dp(indi+1, indj-1,s);
        return ans = max(dp(indi+1, indj,s), dp(indi, indj-1,s));
    }
};

//PLUS (DP TOP DOWN)
//Recovering Longest Palindromic Subsequence 
class Solution {
public:
    int memo[1005][1005];
    string longestPalindrome(string s) {
        memset(memo, -1, sizeof(memo));
        int lg = dp(0, s.size()-1, (char*)s.c_str());
        string ansA = recoverA(0, s.size()-1, (char*)s.c_str());
        string ansB = recoverB(0, s.size()-1, (char*)s.c_str());
        return ansA+ansB;
    }
    
    int dp(int indi, int indj, char* s){ //Dp to find the size of longest palindromic subsequence
        if(indi > indj) return 0;
        int& ans = memo[indi][indj];
        if(ans != -1) return ans;
        if(s[indi] == s[indj]) return ans = (indj == indi?1:2)+ dp(indi+1, indj-1,s);
        return ans = max(dp(indi+1, indj,s), dp(indi, indj-1,s));
    }
    string maxstr(string &a, string &b){ //return the bigger string
        return a.size() > b.size()? a : b;
    }
    string recoverA(int i, int j, char* s){ //Recover the left side of the palindromic string
        if(i>j) return "";
        int inc = 0;
        if(s[i] == s[j]) return s[i]+recoverA(i+1, j-1, s);
        int a = dp(i+1, j, s);
        int b = dp(i, j-1, s);
        if(a > b) return recoverA(i+1, j, s);
        else return recoverA(i, j-1, s);
    }
    string recoverB(int i, int j, char* s){ //Recover the right side of the palindromic string
        if(i>j) return "";
        int inc = 0;
        if(s[i] == s[j]) {
            if(i != j ) return s[j]+recoverB(i+1, j-1, s);
            else return ""+recoverB(i+1, j-1, s);
        }
        int a = dp(i+1, j, s);
        int b = dp(i, j-1, s);
        if(a > b) return recoverB(i+1, j, s);
        else return recoverB(i, j-1, s);
    }
};