//https://www.urionlinejudge.com.br/judge/pt/problems/view/2767
//URI 2767 - Festa
#include <bits/stdc++.h>
using namespace std;
//K = 6, H = 3
int main(){
    unordered_map<int,int> count;
    int n, m, k;
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        count.clear();
        for(int i = 0; i < n ; ++i){
            int a; cin >> a;
            a %= k;
            count[a]++;
        }
        long long sum = 0LL;
        for(int j = 0; j < m ; ++j){
            int a; cin >> a;
            a = (k - (a%k))%k;
            sum+=count[a];
        }

        printf("%lld\n", sum);
    }
    return 0;
}