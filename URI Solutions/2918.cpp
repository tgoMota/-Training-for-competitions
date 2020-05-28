//https://www.urionlinejudge.com.br/judge/pt/problems/view/2918
//URI | 2918 Dígitos Inteligentes
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

ll memo[20][2][2][2][180];

ll solve(int idx, bool tightA, bool tightB, bool valid, int sum, const int N, string& a, string& b){
    if(idx == N) return valid ? sum : 0LL;
    ll& ans = memo[idx][tightA][tightB][valid][sum];
    if(ans != -1) return ans;
    int limitA = tightA ? a[idx]-'0' : 0;
    int limitB = tightB ? b[idx]-'0' : 9;
    ans = 0LL;
    for(int i = limitA; i <= limitB ; ++i){
        bool newTightA = tightA && i <= a[idx]-'0';
        bool newTightB = tightB && i >= b[idx]-'0';
        bool stilValid = valid || i > 0;
        ans = (ans+ solve(idx+1, newTightA, newTightB, stilValid, sum+i, N, a, b))%mod;
    }
    return ans;
}

int main(){
    fastio();
    string a, b;
    while(cin >> a >> b && !cin.eof()){
        const int N = a.size(), M = b.size();
        if(N < M) a.insert(a.begin(), M-N, '0');
        memset(memo, -1, sizeof(memo));
        cout << solve(0,true,true,0,0,M, a, b) << '\n';
    }
    return 0;
}