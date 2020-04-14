#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, q, lq, lr, lp;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &q, &lq, &lr, &lp);
        int ans = (q*lq + q*lr)/lp;
        ans = (q*lq + q*lr)%lp == 0 ? ans : ++ans;
        printf("O livro contera %d %s.\n", ans, ans>1? "paginas":"pagina");
    }

    return 0;
}