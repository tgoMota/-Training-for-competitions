#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int n, a, r, m;
vector<ll> v;

ll check(ll h){
    ll removeBrick = 0LL, putBrick = 0LL;
    for(int i = 0; i < n ; ++i){
        if(v[i] > h) removeBrick += v[i]-h;
        else putBrick += h-v[i];
    }

    ll removeAndPut = min(removeBrick, putBrick);
    ll bestWay = removeAndPut*m + (removeBrick-removeAndPut)*r + (putBrick-removeAndPut)*a;
    return bestWay;
}

int main(){
    
    scanf("%d%d%d%d", &n, &a, &r, &m);
    // a => put a brick on top of one pillar
    // r => remove a brick from the top of one non-empty pillar
    // m => move a brick from the top of one non-empty pillar to the top of another pillar
    m = min(m, a+r);
    v.resize(n);
    ll minh = ooLL, maxh = -ooLL;
    for(int i = 0; i < n ; ++i) {
        scanf("%lld", &v[i]);
        minh = min(minh, v[i]);
        maxh = max(maxh, v[i]);
    }

    ll lo = minh, hi = maxh, ans = check(hi);
    while(lo < hi){
        ll mid = lo + (hi-lo)/2;
        ll left = check(mid);
        ll right = check(mid+1);
        ans = min({ans, left, right});
        if(check(mid) <= check(mid+1)) hi = mid;
        else lo = mid+1;
    }

    printf("%lld\n", ans);

    return 0;
}