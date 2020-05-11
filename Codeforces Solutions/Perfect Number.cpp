//https://codeforces.com/contest/919/problem/B
//B. Perfect Number
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
 
ll memo[20][2][10];
ll solve(int idx, bool tight, int sum, string& num, const int N){
    if(idx == N) return sum == 10;
    if(memo[idx][tight][sum] != -1 && !tight) return memo[idx][tight][sum];
    int limit = tight? num[idx]-'0' : 9;
    ll ans = 0LL;
    for(int i = 0; i <= limit ; ++i){
        bool newTight = num[idx] - '0' == i ? tight : 0;
        if(sum + i > 10) break;
        ans += solve(idx+1, newTight, sum+i, num, N);
    }
    if(!tight) memo[idx][tight][sum] = ans;
    return ans;
}

void test(){
    int k;
    ll a, b;
    while(scanf("%lld", &k) && k){
        memset(memo, -1, sizeof(memo));
        string str = to_string(k);
        printf("%lld\n", solve(0,1,0,str, (int)str.size()));
    }
}

int main(){
   // test();
    int k;
    scanf("%d", &k);
    ull lo = 0, hi = 1e19, ans;
    string str;
    while(lo < hi){
        ull mid = lo + (hi-lo)/2ULL;
        memset(memo, -1, sizeof(memo));
        str = to_string(mid);
        ll r = solve(0,1,0,str, (int)str.size());
        if(r >= k) hi = mid;
        else lo = mid+1;
    }

    printf("%llu\n", lo);
    return 0;
}