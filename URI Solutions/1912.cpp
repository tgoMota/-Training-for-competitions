//https://www.urionlinejudge.com.br/judge/pt/problems/view/1912
//URI 1912 Ajude Seu Madruga
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll N, A;
vector<ll> v;

const long double EPS = 1e-10;
int cmp(long double x, long double y = 0){
    return( x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}


ld can(double m){
    ld rest = 0;
    for(int i = 0; i < N; ++i){
        if(v[i] > m) rest += v[i]-m;
    }
    return rest;
}

int main(){
    while(scanf("%lld%lld", &N, &A) && N+A){
        v.resize(N);
        ll sum = 0LL;
        for(ll& x : v) {
            scanf("%lld", &x);
            sum += x;
        }
        sort(v.begin(), v.end());
        ld hi = ld(v.back()), lo = 0.0;
        int lg = (int)ceil(log2(hi));
        while(cmp(lo,hi) == -1){
            ld mid = (lo+hi)/2.0;
            ld rest = can(mid);
            if(cmp(A,rest) == 0) {
                lo = mid;
                break;
            }
            if(cmp(rest,A) == 1) lo = mid;
            else hi = mid;
        }

        if(A == 0 || sum == A) printf(":D\n");
        else if(A > sum) printf("-.-\n");
        else printf("%.4Lf\n", lo+EPS);
    }
    return 0;
}