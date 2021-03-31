#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        pair<int,int> mx = {0,1};
        for(int i = 2; i < n ; i+=2){
          int summx = v[mx.first] + v[mx.second];
          int new_sum = v[i]+v[i-1];
          if(new_sum < summx) mx = {i-1,i};
        }

        ll ans = 0LL;
        int l = 0, r = 0;
        for(int i = 0; i < mx.first ; ++i){
          l += (i%2 == 0);
          r += (i%2 != 0);
          ans += v[i];
        }
        l = n-l;
        r = n-r;
        trace(ans, l, r, mx.first, mx.second, v[mx.first], v[mx.second]);
        ans+= l*v[mx.first]+r*v[mx.second];
        cout << ans << '\n';
    }
    return 0;
}
