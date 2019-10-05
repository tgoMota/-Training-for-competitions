#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000}, N = 11;
ll memo[12][30001];
ll pd(int d, int ind){
    if(d <= 0 || ind == N) return d == 0;
    ll& ans = memo[ind][d];
    if(ans != -1) return ans;
    return ans = pd(d-coins[ind], ind) + pd(d, ind+1);
}

int main(){
    double k;
    while(scanf("%lf", &k) && k != 0.00){
        memset(memo, -1, sizeof(memo));
        k += 1e-7;
        printf("%6.2lf%17lld\n",k ,pd((int)(k*100),0));
    }
    return 0;
}
