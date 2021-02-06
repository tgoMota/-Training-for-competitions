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
const int NAX = 1000000;
bool test(int x, int y, int z){
  return x*x + y*y == z*z;
}
int gcd(int a, int b, int c){
  return __gcd(a, __gcd(b,c));
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
      set<int> used;
      int triples = 0;
      for(int x = 1; x <= n; ++x){
        for(int y = x+1; y <= n ; ++y){
          if(__gcd(x,y) != 1) continue;
          for(int z = y+1; z <= n ; ++z){
            if(gcd(x,y,z) == 1 && test(x,y,z)){
              triples++;
              used.insert(x);
              used.insert(y);
              used.insert(z);
            }
          }
        }
      }

      int allused = (int)used.size();
      printf("%d %d\n", triples, n-allused);
    }
    return 0;
}
