//https://www.urionlinejudge.com.br/judge/pt/problems/view/3067
//URI 3067 - Dominó
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
vector<vector<int>> adj;
vector<bool> vst;

void dfs(int v){
  if(vst[v]) return;
  vst[v] = true;
  for(int x : adj[v]) dfs(x);
}

int main(){
    fastio();
    int n, t = 1;
    while(cin >> n && n){
      adj.assign(7, vector<int>());
      int a, b;
      for(int i = 0; i < n ; ++i){
        cin >> a >> b;
        if(a < b) swap(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
      

      vst.assign(7, false);
      dfs(a);
      bool ok =  true;
      int butts = 0;
      for(int i = 0; i <= 6 ; ++i){
        if(adj[i].empty()) continue;
        if((int)adj[i].size() % 2) butts++;
        if(!vst[i] || butts > 2) {
          ok = false;
          break;
        }
      }

      cout << "Teste " << t++ << '\n';
      cout << (ok ? "sim" : "nao") << '\n';
      cout << '\n';
    }
    return 0;
}
