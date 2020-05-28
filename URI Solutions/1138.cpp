//https://www.urionlinejudge.com.br/judge/pt/problems/view/1138
//URI 1138 - Contagem de Dígitos
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
ll memo[20][2][2][2][20];

ll solve(int idx, bool tightA, bool tightB, bool valid, int sum, string& a, string& b, const int N, const int D){
    if(idx == N) return valid ? sum : 0LL;
    ll& ans = memo[idx][tightA][tightB][valid][sum];
    if(ans != -1) return ans;
    ans = 0LL;
    int limitA = tightA ? a[idx]-'0' : 0;
    int limitB = tightB ? b[idx]-'0' : 9;
    for(int i = limitA ; i <= limitB ; ++i){
        bool newTightA = tightA && (i <= a[idx]-'0');
        bool newTightB = tightB && (i >= b[idx]-'0');
        bool newValid = valid || i > 0;
        int add = newValid && (i == D);
        ans += solve(idx+1, newTightA, newTightB, newValid, sum + add, a, b, N, D);
    }
    return ans;
}
int main(){
    fastio();
    string A, B;
    while(cin >> A >> B && (A != "0" || B != "0")){
        const int N = A.size();
        const int M = B.size();
        if(N < M) A.insert(0, M-N, '0');
        for(int i = 0; i < 10 ; ++i){
            memset(memo, -1, sizeof(memo));
            ll ans = solve(0,1,1,0,0, A, B, M, i); 
            cout << ans;
            if(i != 9) cout << " ";
        }
        cout << endl;
    }
    return 0;
}