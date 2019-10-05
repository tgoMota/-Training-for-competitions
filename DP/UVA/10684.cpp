//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1625
#include <bits/stdc++.h>
using namespace std;

int n, bet[10001];

int main(){
    while(scanf("%d", &n) && n){
        for(int i = 1; i <= n ; ++i) cin >> bet[i];
        int ans = 0, sum = 0;
        for(int i = 1; i <= n ; ++i){
            sum+=bet[i];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        if(!ans) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", ans);
    }

    return 0;
}
