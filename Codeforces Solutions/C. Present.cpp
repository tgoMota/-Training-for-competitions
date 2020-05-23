//https://codeforces.com/contest/460/problem/C
//C. Present
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int n, m, w;
vector<ll> v;
int check(ll x){
    vector<int> s(n,0);
    int cnt = 0, day = 0;
    for(int i = 0; i < n ; i++){
        day = i-w >= 0 ? day-s[i-w] : day;
        if(v[i]+day < x){
            s[i] = x-v[i]-day;
            day+=s[i];
            cnt+=s[i];
        }
        if(cnt>m) return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d%d", &n, &m, &w);
    v.resize(n);
    ll minx = ooLL, maxx = -ooLL;
    for(ll& x : v) {
        scanf("%lld", &x);
        minx = min(minx, x);
        maxx = max(maxx, x);
    }

    ll lo = minx, hi = maxx+m, ans = 0;
    int maxit = (int)log2(lo+hi)+1;
    for(int i = 0; i < maxit ; ++i){
        ll mid = lo + (hi-lo)/2;
        if(check(mid)) lo = mid+1, ans = mid;
        else hi = mid-1;
    }

    printf("%lld\n", ans);

    return 0;
}