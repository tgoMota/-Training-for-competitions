//https://www.urionlinejudge.com.br/judge/pt/problems/view/1286
//URI 1286 - Motoboy
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
vector<pair<int,int>> v;
int n, m, memo[21][31];
int solve(int r, int ind){
    if(r < 0) return -oo;
    if(ind == n) return 0;
    int& ans = memo[ind][r];
    if(ans != -1) return ans;
    return ans = max(v[ind].first+solve(r-v[ind].second, ind+1), solve(r,ind+1));
}

int main(){
    while(scanf("%d", &n) && n){
        scanf("%d", &m);
        for(int i = 0; i < n ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            v.push_back(make_pair(a,b));
        }
        memset(memo, -1, sizeof(memo));
        printf("%d min.\n", solve(m, 0));
        v.clear();
    }
    return 0;
}