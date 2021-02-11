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
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<ll> v(n);
        for(ll& x : v) scanf("%lld", &x);
        vector<ll> vb(v.begin(), v.end());
        bool ok = true;
        for(int i = 1; i < n-1 ; ++i){
          if(v[i-1] > v[i]){
            swap(v[i], v[i+1]);
            if(v[i-1] > v[i]){
              //trace(i);
              ok = false;
              break;
            }
          }
          v[i]-=v[i-1];
          v[i-1] = 0;
        }
        //trace(ok, v[n-1], v[n-2]);
        ok = ok && v[n-1] == v[n-2];
        if(ok){
          printf("YES\n");
          continue;
        }
        ok = true;
        reverse(v.begin(), v.end());
        for(int i = 0; i < n ; ++i) v[i] = vb[i];
        for(int i = 1; i < n-1 ; ++i){
          if(v[i-1] > v[i]){
            swap(v[i], v[i+1]);
            if(v[i-1] > v[i]){
              //trace(i);
              ok = false;
              break;
            }
          }
          v[i]-=v[i-1];
          v[i-1] = 0;
        }
        ok = ok && v[n-1] == v[n-2];
        if(ok){
          printf("YES\n");
        }else{
          printf("NO\n");
        }
    }
    return 0;
}
