//https://www.urionlinejudge.com.br/judge/pt/problems/view/1520
//URI 1520 - Parafusos e Porcas
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
    int n;
    while(scanf("%d", &n) != EOF){
      vector<int> pref(102, 0);
      for(int i = 0; i < n ; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        pref[a]++;
        pref[b+1]--;
      }
      for(int i = 1; i < 101; ++i) pref[i]+=pref[i-1];
      int k;
      scanf("%d", &k); 
      
      int idx = 0;
      for(int i = 0; i < k ; ++i){
        idx += pref[i] > 0 ? pref[i] : 0;
      }
      if(pref[k] == 0) printf("%d not found\n", k);
      else printf("%d found from %d to %d\n", k, idx, idx+pref[k]-1);
    }
    return 0;
}
