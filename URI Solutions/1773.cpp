//https://www.urionlinejudge.com.br/judge/pt/problems/view/1773
//URI 1773 - Preso no Castelo
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
int N, M;
vector<vector<int>> adj;
vector<vector<int>> cango;

int main(){
    while(scanf("%d%d", &N, &M) != EOF){
      adj.assign(N, vector<int>());
      cango.assign(N, vector<int>());
      for(int i = 0; i < M ; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
      }

      for(int i = 1; i <= N-1 ; ++i){
        int k;
        scanf("%d", &k);
        cango[--k].push_back(i);
      }
      vector<bool> vst(N, false);
      int cnt = 0;
      set<int> unlocked, adjorder;
      unlocked.insert(0);
      adjorder.insert(0);
      while(!adjorder.empty()){
        int u = -1;
        for(int x : adjorder){
          if(vst[x]) continue;
          if(unlocked.find(x) != unlocked.end()){
            u = x;
            break;
          }
        }
        if(u == -1) break;
        if(++cnt == N) break;
        vst[u] = true;
        for(int x : cango[u]) unlocked.insert(x);
        for(int a : adj[u]){
          if(vst[a]) continue;
          adjorder.insert(a);
        }
      }
      printf("%s\n", cnt == N ? "sim" : "nao");
    }
    return 0;
}
