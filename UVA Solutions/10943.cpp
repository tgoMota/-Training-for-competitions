#include <bits/stdc++.h>
using namespace std;

int memo[101][101];
const int mod = 1e6;

int solve(int n, int k){
    if(k == 1) return 1;
    int& ans = memo[n][k];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0; i <= n ; ++i){
        ans = ((ans % mod) + (solve(n-i, k-1))%mod)%mod;
    }
    return ans;
}

int main(){
    int n, k;
    while(cin >> n >> k && n + k > 0){
        memset(memo, -1, sizeof(memo));
        cout << solve(n,k) << endl;
    }

    return 0;
}