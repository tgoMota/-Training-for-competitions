#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int coins[] = {5, 10, 20, 50, 100, 200}, disp[6], N = 6, memo[7][510];

int pd(int money, int ind){
    if(money < 0) return oo;
    if(ind == N) return money == 0 ? 0 : oo;
    int& ans = memo[ind][money];
    if(ans != -1) return ans;
    return min({pd(money-coins[ind], ind)+1,pd(money, ind+1), pd(money+coins[ind],ind) + 1});
}

int main(){
    double r;
    while(1){
        int sum = 0;
        for(int i = 0; i < N ; ++i) {
            scanf("%d", disp[i]);
            sum += disp[i];
        }
        if(!sum) break;
        scanf("%lf", &r);
        r += 1e-7;
        r *= 100;
        memset(memo, -1, sizeof(memo));
        printf("%d\n", pd((int)r, 0));
    }
}
