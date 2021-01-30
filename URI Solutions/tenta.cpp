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
int n;
vector<vector<int>> adj;
vector<bool> vst;
vector<int> match;

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

int main(){
    while(scanf("%d", &n) != EOF){
      adj.assign(n+1, vector<int>());
      for(int i = 1; i <= n ; ++i){
        int a;
        scanf("%d", &a);
        adj[a].push_back(i);
        adj[i].push_back(a);
      }

      int mcbm = 0;
      match.assign(n+1, -1);
      for(int i = 1; i <= n ; ++i){
        vst.assign(n+1, false);
        mcbm += aug(i);
      }

      if(n%2 || mcbm < n/2) printf("IMPOSSIBLE\n");
      else{
        set<ii> duos;
        vector<bool> used(n+1, false);
        for(int i = 1; i <= n ; ++i){
          int a = min(i, match[i]);
          int b = max(i, match[i]);
          if(a == -1 || b == -1) continue;
          if(!used[a] && !used[b]) {
            duos.insert({a,b});
            used[a] = used[b] = true;
          }
        }
        vector<int> ans(n+1, -1);
        vector<int> happens(n+1, 0);
        vector<ii> toOrder;
        for(ii x : duos){
          int u = x.first, v = x.second;
          happens[u]++;
          happens[v]++;
          toOrder.push_back(x);
        }

        // set<ii> byHappens;
        // for(int i = 1; i <= n ; ++i){
        //   byHappens.insert({happens[i], i});
        // }
        sort(toOrder.begin(), toOrder.end(), [&](ii& a, ii& b){
          int mina = min(happens[a.first], happens[a.second]);
          int minb = min(happens[b.first], happens[b.second]);
          if(mina == minb) return min(a.first, a.second) < min(b.first, b.second);
          return mina < minb;
        });
        for(ii x : toOrder) {
          //printf("{%d,%d} ", x.first, x.second);
          if(ans[x.first] != -1  || ans[x.second] != -1) continue;
          ans[x.first] =  x.second;
          ans[x.second] = x.first;
        }
        bool ok = true;
        for(int i = 1; i <= n ; ++i){
          if(ans[i] == -1){
            ok = false;
            break;
          }
        }
        if(!ok){
          printf("IMPOSSIBLE\n");
          continue;
        }
        for(int i = 1; i <= n ; ++i){
          printf("%d", ans[i]);
          if(i != n) printf(" ");
        }
        printf("\n");
      }
    }
    return 0;
}
