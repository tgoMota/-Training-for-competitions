//https://codeforces.com/problemset/problem/431/C
//C. k-Tree
#include <bits/stdc++.h>
using namespace std;
int n, k, d, mod = 1e9 + 7;
long long memo[105][2];

long long pd(int sum, bool passou){
    if(sum >= n) return sum==n && passou;
    long long& ans = memo[sum][passou];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 1 ; i <= k ; ++i) {
        if(i >= d) ans = (ans%mod+ pd(sum+i,true) % mod)%mod;
        else ans = (ans%mod+ pd(sum+i,passou) % mod)%mod;
    }
    return ans;
}

int main(){
    cin >> n >> k >> d;
    memset(memo, -1, sizeof(memo));
    cout << pd(0,false) << endl;

    return 0;
}
