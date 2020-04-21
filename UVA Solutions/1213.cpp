#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> primes;
ll n, k, memo[15][1121][300], eh;
ll pd(int num, int ki, int ind){
    if(ki == 0 || num < 0) return num == 0;
    if(primes[ind] > n || ki < 0) return 0;
    ll& ans = memo[ki][num][ind];
    if(ans != -1LL) return ans;
    return ans = pd(num - primes[ind],ki-1,ind+1) + pd(num,ki,ind+1);
}
int main(){
    primes.push_back(2);
    for(int i = 3; i <= 1130 ; ++i){
        eh = 1;
        for(int j = 2; j <= sqrt(i) ; ++j){
            if(i % j == 0) {eh = 0; break;}
        }
        if(eh) primes.push_back(i);
    }

    while(scanf("%d%d", &n, &k)){
        if(n == 0 && k == 0) break;
        memset(memo, -1, sizeof(memo));
        printf("%lld\n", pd(n, k, 0));
    }

    return 0;
}