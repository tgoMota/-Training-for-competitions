//https://www.urionlinejudge.com.br/judge/pt/problems/view/1034
//URI 1034 - Festival de Estátuas de Gelo
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
vector<int> blocks;
int N, M;
int memo[1000001];

int solve(int m){
    if(m == M) return 0;
    if(m > M) return oo;
    int& ans = memo[m];
    if(ans != -1) return ans;
    ans = oo;
    for(int i = 0; i < N ; ++i) ans = min(ans, 1+solve(m+blocks[i]));
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &N, &M);
        blocks.assign(N,0);
        for(int& x : blocks) scanf("%d", &x);
        memset(memo, -1, sizeof(memo));
        printf("%d\n", solve(0));
    }


    return 0;
}