// //https://codeforces.com/problemset/problem/166/E
// #include <bits/stdc++.h>
// using namespace std;
// #define mod 1000000007
// typedef long long ll;
// const int N = 10000010;
// //int memo[2][N];
 
// // int pd(int r, int i){
// //     if(r == 0) return i == 1;
// //     int& ans = memo[i==1][r];
// //     if(ans != -1) return ans;
// //     ans = 0;
// //     for(int j = 1; j <= 4 ; ++j){
// //         if(j != i) ans = (ans % mod + pd(r-1,j)%mod)%mod;
// //     }
// //     return ans;
// // }

// int pd(int r, int i){
//     if(r == 0) return i == 1;
//     int ans = vis[{i==1,r}];
//     if(ans != 0) return ans;
//     ans = 0;
//     for(int j = 1; j <= 4 ; ++j){
//         if(j != i) ans = (ans % mod + pd(r-1,j)%mod)%mod;
//     }
//     return vis[{i==1,r}] = ans;
// }
 
// int main(){
//     int n;
//     cin >> n;
//    // memset(memo, -1, sizeof(memo));
//     printf("%d\n", pd(n,1));
 
//     return 0;
// }

//https://codeforces.com/problemset/problem/166/E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp map <pair<int,ll>, ll> 
#define mod 1000000007
mp vis;

ll pd(ll r, int i){
    if(r == 0LL) return i == 1;
    ll ans = vis[{i==1,r}];
    if(ans != 0) return ans;
    ans = 0LL;
    for(int j = 1; j <= 4 ; ++j){
        if(j != i) ans = (ans % mod + pd(r-1LL,j)%mod)%mod;
    }
    return vis[{i==1,r}] = ans;
}
 
int main(){
    ll n;
    cin >> n;
    printf("%d\n", pd(n,1));
 
    return 0;
}