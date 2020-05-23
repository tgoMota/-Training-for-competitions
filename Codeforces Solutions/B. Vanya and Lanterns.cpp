//https://codeforces.com/contest/492/problem/B
//B. Vanya and Lanterns
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    scanf("%d%d", &n, &l);
    vector<int> v(n);
    for(int i = 0; i < n ; ++i) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    double ans = max(v[0], l-v.back());
    for(int i = 1; i < n ; ++i){
        ans = max(ans, (v[i]-v[i-1])/2.0);
    }
    printf("%.10lf\n", ans);
    return 0;
}