//http://codeforces.com/problemset/problem/492/B
//B. Vanya and Lanterns
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, l, la[1001], ai;

int main(){
    double ans;
    scanf("%lld%lld", &n, &l);
    for(int i = 1; i <= n ; ++i) scanf("%lld", &la[i]);
    sort(la+1, la+n+1);
    ans = max(l - la[n], la[1]);
    for(int i = 1; i <= n ; ++i) ans = max(ans,(la[i]-la[i-1])/2.0);
    printf("%.10lf\n", ans);

    return 0;
}
