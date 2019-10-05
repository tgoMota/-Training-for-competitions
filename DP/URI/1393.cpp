//https://www.urionlinejudge.com.br/judge/pt/problems/view/1393
#include <bits/stdc++.h>
using namespace std;

int memo[41], n;

int pd(int ind){
    if(ind >= n) return ind==n;
    int& ans = memo[ind];
    if(ans != -1) return ans;
    return ans = pd(ind+1) + pd(ind+2);
}

int main(){
    while(scanf("%d", &n) && n){
        memset(memo, -1, sizeof(memo));
        printf("%d\n", pd(0));
    }
    return 0;
}
