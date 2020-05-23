//https://codeforces.com/contest/166/problem/E
//Bottom-Up DP (Accepted)
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
const int mod = 1e9+7;
typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);

    vector<vector<int>> dp(4, vector<int>(n+1, 0));
    dp[0][1] =  dp[1][1] = dp[2][1] = 1; //raiz => 3
    for(int step = 2; step <= n ; ++step){
        for(int no = 0; no < 4 ; ++no){
           for(int prev = 0; prev < 4 ; ++prev){
               if(prev == no) continue;
               dp[no][step] = (dp[no][step] + dp[prev][step-1])%mod;
           }
        }
    }

    printf("%d\n", dp[3][n]);

    return 0;
}

//Top-down DP (Memory limit exceeded)
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int mod = 1e9+7;
// vector<vector<int>> memo;
 
// int pd(int r, int i){
//     if(r == 0) return i == 1;
//     int& ans = memo[i==1][r];
//     if(ans != -1) return ans;
//     ans = 0;
//     for(int j = 1; j <= 4 ; ++j){
//         if(j != i) ans = (ans + pd(r-1,j)%mod)%mod;
//     }
//     return ans;
// }

// int main(){
//     int n;
//     scanf("%d", &n);
//     memo.assign(2,vector<int>(n+1, -1));
//     printf("%d\n", pd(n,1));
 
//     return 0;
// }
