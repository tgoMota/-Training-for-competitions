#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[20][20][2];

ll solve(int idx,int sum,bool tight, string& num){
    if(idx == num.length()) return sum;
    ll& ans = memo[idx][sum][tight];
    if(ans != -1) return ans;

    int limit = (tight ? num[idx]-'0' : 9);
    ans = 0LL;
    for(int i = 0; i <= limit ; ++i){
        bool newTight = (num[idx]-'0' == i)? tight : 0;
        int isOneOrSeven = (i == 1) || (i == 7);
        ans+= solve(idx+1, sum+isOneOrSeven, newTight, num);
    }
    return ans;
}

int main(){
    ll n;
    scanf("%lld", &n);
    
    string num = to_string(n);
    memset(memo, -1, sizeof(memo));
    printf("%lld\n", solve(0, 0, true, num));

    return 0;
}