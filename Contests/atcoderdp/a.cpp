#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n ; ++i) cin >> v[i];
    vector<int> dp(n+1, oo);
    dp[0] = 0;
    for(int i = 1; i < n ; ++i){
        for(int x : {i-1, i-2}){
            if(x < 0) continue;
            dp[i] = min(dp[i], dp[x]+abs(v[i]-v[x]));
        }
    }
    printf("%d\n", dp[n-1]);

    return 0;
}