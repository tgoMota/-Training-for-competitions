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
vector<ll> v;
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
      ll n, x;
      scanf("%lld%lld", &n, &x);
      ll sum1=0LL, sum2=0LL,sum=0LL;
      for(int i=0;i<n;i++){
          ll a;
          scanf("%lld", &a);
          sum1+=ceil(a/(double)x);
          sum+=a;
      }
      sum2+=ceil(sum/(double)x);
      ll maxx=max(sum1, sum2);
      ll minx=min(sum1,sum2);
      printf("%lld %lld\n", minx, maxx);

    }
    return 0;
}
