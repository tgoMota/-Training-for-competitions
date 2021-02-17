//https://www.urionlinejudge.com.br/judge/pt/problems/view/2884
//URI 2884 - Interruptores
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
int n, m, l;
vector<int> all;
vector<vector<int>> interrup;
int main(){
    scanf("%d%d", &n,&m);
    interrup.assign(n+1, vector<int>());
    all.assign(m+1, 0);
    scanf("%d", &l);
    for(int i = 0; i < l ; ++i){
      int a;
      scanf("%d", &a);
      all[a] = 1;
    }

    for(int i = 1; i <= n ; ++i){
      int a;
      scanf("%d", &a);
      interrup[i].resize(a+1);
      interrup[i][0] = a;
      for(int j = 1; j <= a ; ++j) scanf("%d",&interrup[i][j]);
    }
    int idx = 1;
    bool ok = false;
    int ans = 0;
    for(int i = 0; i < n*m ; ++i){
      ans++;
      for(int j = 1; j <= interrup[idx][0] ; ++j){
        int light = interrup[idx][j];
        all[light] ^= 1;
      }

      bool check = true;
      for(int j = 1; j <= m ; ++j){
        if(all[j]){
          check = false;
          break;
        }
      }
      if(check){
        ok = true;
        break;
      }
      idx++;
      if(idx > n) idx = 1;
    }

    if(ok) printf("%d\n", ans);
    else printf("-1\n");

    return 0;
}
