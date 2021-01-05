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
    deque<pair<ll,ll>> dq;
    for(int ti = 1; ti <= t ; ++ti){
        ll n, x;
        scanf("%lld%lld", &n, &x);
        dq.clear();
        for(int i = 0; i < n ; ++i){
          ll a;
          scanf("%lld", &a);
          dq.push_back({1LL,a});
        }
        ll sum = 0LL;
        bool ok = true;
        while(!dq.empty()){
          pair<ll,ll> a = dq.front();
          dq.pop_front();
          sum += a.first*a.second;
          if(a.second%x != 0 && ok) ok = false;
          if(!ok) continue;
          dq.push_back({a.first*x, a.second/x});
        }
        printf("%lld\n", sum);
    }
    return 0;
}
