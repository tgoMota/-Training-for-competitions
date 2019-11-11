//https://www.urionlinejudge.com.br/judge/pt/problems/view/2776
//URI 2776 - Promoções
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int n, m, memo[1002][2005];
typedef vector<pair<int,int>> vii;
vii sales;

int dp(int ind, int sold){
    if(sold > m || ind == n && sold < m) return -oo;
    if(ind == n || sold == m) return 0;
    int& ans = memo[ind][sold];
    if(ans != -1) return ans;
    return ans = max(dp(ind+1, sold), sales[ind].second + dp(ind, sold+sales[ind].first));
}

int main(){

    while(scanf("%d%d", &n, &m) != EOF){
        sales.assign(n, {0,0});
        memset(memo, -1, sizeof(memo));
        for(auto& x : sales) scanf("%d%d", &x.first, &x.second);
        int ans = dp(0,0);
        printf("%d\n", ans<0?-1:ans);
    }
    return 0;
}