//https://www.urionlinejudge.com.br/judge/pt/problems/view/2934
//URI 2934 - Noel e Suas Renas
#include <bits/stdc++.h>
using namespace std;
//CHECK THE LIMITS, PLEASE
vector<int> v;

int main(){
    int n;
    scanf("%d", &n);
    v.resize(n);
    for(int& x : v) scanf("%d", &x);
    int dp[(int)1e6+5][2];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int idx = 0; idx < n ; ++idx){
      dp[v[idx]][0] = max(dp[v[idx]][0],dp[v[idx]-1][0]+1);
      if(v[idx]>=2) {
        dp[v[idx]][1] = max({dp[v[idx]][1],dp[v[idx]-2][0]+2, dp[v[idx]-1][1]+1});
      }
      ans = max({ans,dp[v[idx]][0]+1, dp[v[idx]][1]});
    }

    printf("%d\n", ans);
    return 0;
}
