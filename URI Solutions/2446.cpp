//urionlinejudge.com.br/judge/pt/problems/view/2446
//URI 2446 - Troco
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int V, M;
int memo[100005][1005];

int solve(int i, int v, vector<int>& coins){
    if(v == 0) return 1;
    if(i >= M || v < 0) return 0;
    int& ans = memo[v][i];
    if(ans != -1) return ans;
    return ans = solve(i+1, v-coins[i], coins) || solve(i+1, v, coins);
}

int main(){
    scanf("%d%d", &V, &M);
    vector<int> coins(M);
    for(int& x : coins) scanf("%d", &x);
    memset(memo, -1, sizeof(memo));
    if(solve(0, V, coins)) printf("S\n");
    else printf("N\n");
    return 0;
}