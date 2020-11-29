//https://www.urionlinejudge.com.br/judge/pt/problems/view/1616
//URI 1616 - Baile de formatura
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
const int MX = 1005;
const int MOD = 1e9+7;
ll A, B;
ll memo[MX][MX];
ll solve(ll a, ll b){
    if(a == 0) return b == 0; //ultima garota, precisa dançar com ao menos 1 garoto
    ll& ans = memo[a][b];
    if(ans != -1) return ans;
    return ans = ((solve(a-1, b) * (B-b))%MOD + (solve(a-1, b-1)*b)%MOD)%MOD;

}


int main(){
    while(scanf("%lld%lld", &A, &B) && A+B){
        memset(memo, -1, sizeof(memo));
        printf("%lld\n", solve(A,B));
    }
    return 0;
}