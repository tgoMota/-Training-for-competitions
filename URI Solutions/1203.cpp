//https://www.urionlinejudge.com.br/judge/pt/problems/view/1203
//URI 1203 - Pontes de São Petersburgo
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int memo[102][11235];

int solve(int idx, int K, const int R, const vector<int>& in){
    if(K == 0) return 1;
    if(idx > R || K < 0) return 0;
    int& ans = memo[idx][K];
    if(ans != -1) return ans;
    return ans = (solve(idx+1, K-in[idx], R, in)) || (solve(idx+1, K, R, in));
}

int main(){
    int R, K;
    while(scanf("%d%d", &R, &K) != EOF){
        vector<int> in(R+1);
        for(int i = 1; i <= K ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            in[a]++; in[b]++;
        }
        memset(memo, -1, sizeof(memo));

        if(solve(0,K,R,in)) printf("S\n");
        else printf("N\n");
    }
    return 0;
}