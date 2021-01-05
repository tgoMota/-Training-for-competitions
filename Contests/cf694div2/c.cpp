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
//CHECK THE LIMITS, PLEASE
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> v1(n), v2(m);
        for(int& x : v1) scanf("%d", &x);
        for(int& x : v2) scanf("%d", &x);
        sort(v1.begin(), v1.end(), greater<int>());
        ll ans = 0LL;
        for(int i = 0; i < n ; ++i){
          if(i < m) ans += min(v2[i], v2[v1[i]-1]);
          else ans += v2[v1[i]-1];
        }

        printf("%lld\n", ans);
    }
    return 0;
}
