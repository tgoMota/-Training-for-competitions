//http://codeforces.com/problemset/problem/492/B
//B. Vanya and Lanterns
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, l, la[1001], ai;

int main(){
    double ans;
    scanf("%lld%lld", &n, &l);
    for(int i = 0; i < n ; ++i) scanf("%lld", &la[i]);
    sort(la, la+n);
    
    printf("%.10lf\n", ans);

    return 0;
}
