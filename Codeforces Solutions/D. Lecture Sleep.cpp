#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    int t = 1;
    for(int ti = 1; ti <= t ; ++ti){
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        for(int& x : a) scanf("%d", &x);
        vector<int> b(n);
        for(int& x : b) scanf("%d",&x);
        vector<ll> pref(n, 0LL);
        pref[0] = b[0] ? a[0] : 0LL;
        for(int i = 1; i < n ; ++i) pref[i] += pref[i-1]+ (b[i] ? a[i] : 0LL);
        
        vector<ll> suf(n, 0LL);
        suf[n-1] = b[n-1] ? a[n-1] : 0LL;
        for(int i = n-2; i >= 0 ; --i) suf[i] += suf[i+1] + (b[i] ? a[i] : 0LL);

        vector<ll> prefTot(n, 0LL);
        prefTot[0] = a[0];
        for(int i = 1; i < n ; ++i) prefTot[i] += prefTot[i-1] + a[i];

        ll ans = 0LL;
        for(int i = 0; i+k-1 < n ; ++i){
          int l = i, r = i+k-1;
          ll sum = prefTot[r] - (l > 0 ? prefTot[l-1] : 0LL);
          sum += i ? pref[i-1] : 0LL;
          sum += r+1 < n ? suf[r+1] : 0;
          ans = max(ans, sum);
        }

        printf("%lld\n", ans);
    }
    return 0;
}
