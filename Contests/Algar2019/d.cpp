#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
vector<int> v;
vector<int> sum;
int memo[6010][6010];

int solve(int pos, int a, int b, int c, const int n){
    if(pos == n) return ((a==b) && (a==c)) ? 1 : -oo;
    if(a > b+sum[pos] || a > c+sum[pos] || b > c+sum[pos]) return -oo;
    int& ans = memo[a][b];
    if(ans != -1) return ans;
    return ans = max(solve(pos+1, a+v[pos], b, c, n), max(solve(pos+1, a, b+v[pos], c, n), solve(pos+1, a, b, c+v[pos], n)));
}

int main(){
    int n;
    scanf("%d", &n);
    v.resize(n);
    for(int i = 0; i < n ; ++i) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), greater<int>());
    sum.assign(n+1, 0);
    for(int i = n-1 ; i >= 0 ; i--) sum[i] += v[i] + sum[i+1];
    memset(memo, -1, sizeof(memo));
    printf("%s\n", solve(0,0,0,0, n)> 0 ? "SIM" : "NAO");

    return 0;
}
