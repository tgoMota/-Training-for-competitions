//https://www.urionlinejudge.com.br/judge/pt/problems/view/1282
//URI 1282 Organizando Pacotes
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int N, K;
ll w[1001], p[1001], prefW[1001], prefWP[1001], dp[1005][1005];

ll cost(int l, int r){
    ll sumW = l <= r ? prefW[r-1]-prefW[l-1] : 0LL;
    ll sumWP = l <= r ? prefWP[r-1]-prefWP[l-1] : 0LL;
    return p[r] * sumW - sumWP;
}

void solve(int k, int l, int r, int la, int lb){
    if(l > r) return;
    int mid = (l+r)>>1;
    dp[k][mid] = ooLL;
    int best = -1;
    for(int i = la; i <= lb ; ++i){
        ll c = cost(i+1, mid);
        if(dp[k][mid] > dp[k-1][i] + c){
            dp[k][mid] = dp[k-1][i]+c;
            best = i;
        }
    }
    solve(k, l, mid-1, la, best);
    solve(k, mid+1, r, best, lb);
}

int main(){
    while(scanf("%d%d", &N, &K) != EOF){
        for(int i = 1; i <= N ; ++i) scanf("%lld%lld", &p[i], &w[i]);
        
        prefW[0] = prefWP[0] = 0LL;
        for(int i = 1; i <= N ; ++i) {
            prefW[i] = prefW[i-1] + w[i];
            prefWP[i] = prefWP[i-1] + p[i]*w[i];
        }

        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= N ; ++i) dp[1][i] = cost(1, i);

        for(int i = 2; i <= K ; ++i){
            solve(i, 1, N, 1, N);
        }

        printf("%lld\n", dp[K][N]);
    }

    return 0;
}