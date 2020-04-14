#include <bits/stdc++.h>
using namespace std;
  
int solve(string& s) { 
   int n = s.size(), i, j, cl; 
   vector<vector<int>> dp(n, vector<int>(n, 1));
  
    for (cl=2; cl<=n; cl++) { 
        for (i=0; i<n-cl+1; i++) { 
            j = i+cl-1; 
            if (s[i] == s[j] && cl == 2) dp[i][j] = 2; 
            else if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2; 
            else dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
        } 
    } 
    return dp[0][n-1]; 
} 
  
int main() 
{ 
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), 'a'), s.end());
    printf("%d\n", solve(s));
    return 0; 
}