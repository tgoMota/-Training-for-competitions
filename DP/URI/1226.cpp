//https://www.urionlinejudge.com.br/judge/pt/problems/view/1226
//URI 1226 - Elevador Espacial
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
llu memo[20][2][2];

llu solve(int idx, bool tight, bool wasOne, string& a){
    if(idx == a.length()) return 1;
    llu& ans = memo[idx][tight][wasOne];
    if(ans != -1) return ans;

    int limit = tight ? a[idx]-'0' : 9;
    ans = 0ULL;
    for(int i = 0; i <= limit ; ++i){
        if((wasOne && i == 3) || i == 4) continue;
        bool isOne = (i == 1);
        bool isTight = tight && (i == a[idx]-'0');
        ans += solve(idx+1, isTight, isOne, a);
    }
    return ans;
}

int main(){
    llu n;
    while(scanf("%llu", &n) != EOF){
        llu lo = 0ULL, hi = 1e19, mid;
        while(lo < hi){
            llu mid = lo + (hi-lo)/2ULL;
            string str = to_string(mid);
            memset(memo, -1, sizeof(memo));
            if(solve(0,1,0,str) <= n) lo = mid+1;
            else hi = mid;
        }
        printf("%llu\n", lo);
    }
    return 0;  
}