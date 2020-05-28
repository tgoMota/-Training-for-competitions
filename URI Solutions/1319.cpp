//https://www.urionlinejudge.com.br/judge/pt/problems/view/1319
//URI 1319 Garota Hiperativa
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

vector<vector<int>> adj;
vector<ii> range;
vector<vector<int>> dp;
vector<vector<bool>> exist;
int m , n;

int solve(int u, int p){
    if(range[u].second == m) return 1;
    int& ans = dp[u][p];
    if(ans != -1) return ans;
    ans = 0;
    for(int x : adj[u]){
        if(p == n || !exist[p][x]) ans = (ans + solve(x,u))%mod;
    }
    return ans;
}

int main(){

    while(scanf("%d%d", &m, &n) && m+n){
        range.resize(n);
        for(int i = 0; i < n ; ++i){
            scanf("%d%d", &range[i].first, &range[i].second);
        }
        sort(range.begin(), range.end()); //5 7
        adj.assign(n+1, vector<int>());
        exist.assign(n+1, vector<bool>(n+1, false));
        for(int i = 0; i < n ; ++i){
            for(int j = i+1; j < n ; ++j){
                 if(range[i].first == range[j].first) continue;
                 if(range[j].second <= range[i].second) continue;
                 if(range[i].second < range[j].first) continue;
                 adj[i].push_back(j);
                 exist[i][j] = true;
            }
        }

        dp.assign(n+1, vector<int>(n+1, -1));
        int ans = 0;
        for(int i = 0; i < n && range[i].first == 0 ; ++i){
            ans= (ans + solve(i,n))%mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}