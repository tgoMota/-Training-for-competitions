#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string a, b;
    cin >> a >> b;
    const int N = a.size(), M = b.size();
 
    vector<vector<string>> dp(N+1, vector<string>(M+1, ""));
    for(int i = 1; i <= N ; ++i){
        for(int j = 1; j <= M ; ++j){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + a[i-1];
            else if(dp[i][j-1].size() > dp[i-1][j].size()) dp[i][j] = dp[i][j-1];
            else dp[i][j] = dp[i-1][j];
        }
    }
    printf("%s\n", dp[N][M].c_str());
    return 0;
}