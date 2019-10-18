//https://leetcode.com/problems/longest-common-subsequence/
//1143. Longest Common Subsequence
//DP - Bottom Up Approach
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n1 = text1.size()+1, n2 = text2.size()+1;
        int dp[n1][n2];
        for(int i = 0; i < n1 ; ++i)
            for(int j = 0; j < n2 ; ++j)
                dp[i][j] = 0;
        
        for(int i = 1; i < n1 ; ++i){
            for(int j = 1; j < n2 ; ++j){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n1-1][n2-1];
    }
};

//DP - Top Down Approach
class Solution {
public:
    int memo[1005][1005];
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo, -1, sizeof(memo));
        return dp(text1.size()-1,text2.size()-1,(char *)text1.c_str(), (char *)text2.c_str());
    }
    int dp(int i, int j, char* text1, char* text2){
        if(i < 0 || j < 0) return 0;
        int& ans = memo[i][j];
        if(ans != -1) return ans;
        if(text1[i] == text2[j]) return ans = 1+dp(i-1,j-1,text1,text2);
        return ans = max(dp(i-1,j,text1,text2), dp(i,j-1,text1, text2));
    }
};