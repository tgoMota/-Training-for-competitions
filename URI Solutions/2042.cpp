//https://www.urionlinejudge.com.br/judge/pt/problems/view/2042
//URI 2042 - Fofão da Pérsia
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
typedef pair<int,pii> ppii;
typedef long long ll;

vector<ppii> adj[101];
ll memo[105][1005];

ll solve(int idx, int bi, const int d, const int n){
    if(bi < 0) return -ooLL;
    if(idx == d) return 0LL;
    ll& ans = memo[idx][bi];
    if(ans != -1) return ans;
    ans = -ooLL;
    for(auto x : adj[idx]){
        ans = max(ans, x.second.first + solve(x.first, bi-x.second.second, d, n));
    }
    return ans;
}

int main(){
    int n, m, p, d, b;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &p, &d);
    scanf("%d", &b);
    for(int i = 1; i <= m ; ++i){
        int a, b, c, f;
        scanf("%d%d%d%d", &a, &b, &c, &f);
        adj[a].push_back({b,{c,f}});
        adj[b].push_back({a,{c,f}});
    }

    memset(memo, -1, sizeof(memo));
    ll ans = solve(p,b,d,n);
    printf("%lld\n", ans < 0LL ? -1 : ans);
    
    return 0;
}