//https://www.urionlinejudge.com.br/judge/pt/problems/view/1056
//URI 1056 - Fatores e Múltiplos
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
vector<vector<int>> adj;
vector<int> ca, cb, match;
vector<bool> vst;
int n, m;
int aug(int v){
  if(vst[v]) return 0;
  vst[v] = true;
  for(int u : adj[v]){
    if(match[u] == -1 || aug(match[u])){
      match[u] = v;
      return 1;
    }
  }
  return 0;
}

int maxmatch(){
  int mc = 0;
  for(int i = 0; i < n; ++i){
    vst.assign(n, false);
    mc += aug(i);
  }
  return mc;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d", &n);
        ca.resize(n);
        for(int& x : ca) scanf("%d", &x);
        scanf("%d", &m);
        cb.resize(m);
        adj.assign(n+m, vector<int>());
        for(int& x : cb) scanf("%d", &x);
        for(int i = 0; i < n ; ++i){
          int x = ca[i];
          for(int j = 0; j < m ; ++j){
            int y = cb[j];
            if((x != 0 && y % x == 0) || (x == 0 && y == 0)){
              adj[i].push_back(j+n);
            }
          }
        }
        match.assign(n+m, -1);
        printf("Case %d: %d\n", ti, maxmatch());
    }
    return 0;
}
