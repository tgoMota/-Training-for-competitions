//https://www.urionlinejudge.com.br/judge/pt/problems/view/1209
//URI 1209 - Festas de São Petersburgo 
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
int n, m, k;
vector<vector<int>> adj;
vector<int> deg;
int main(){
    fastio();
    while(cin >> n >> m >> k){
      adj.assign(n+1, vector<int>());
      deg.assign(n+1, 0);
      for(int i = 0; i < m ; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++, deg[b]++;
      }
      queue<int> q;
      for(int i = 1; i <= n ; ++i){
        if(deg[i] < k) q.push(i);
      }
      vector<bool> vst(n+1, false);
      while(!q.empty()){
        int v = q.front();
        q.pop();
        if(vst[v]) continue;
        vst[v] = true;
        for(int x : adj[v]){
          if(vst[x] || --deg[x] >= k) continue;
          q.push(x);
        }
      }
      vector<int> ans;
      for(int i = 1; i <= n ; ++i){
        if(!vst[i]) ans.push_back(i);
      }

      if((int)ans.size() == 0) cout << 0;
      else{
        for(int i = 0; i < (int)ans.size() ; ++i){
          if(i) cout << ' ';
          cout << ans[i];
        }
      }
      cout << '\n';
    }
    return 0;
}

