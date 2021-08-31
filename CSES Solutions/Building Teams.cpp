//https://cses.fi/problemset/task/1668
//Building Teams
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
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i = 0; i < m ; ++i){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<int> color(n+1, -1);
    bool isBipartite = true;
    for(int i = 1; i <= n && isBipartite; ++i){
      if(color[i] != -1) continue;
      color[i] = 0;
      queue<int> q;
      q.push(i);
      while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int x : adj[t]){
          if(color[x] == color[t]){
            isBipartite = false;
            break;
          }
          if(color[x] != -1) continue;
          color[x] = 1-color[t];
          q.push(x);
        }
      }
    }

    if(!isBipartite){
      cout << "IMPOSSIBLE\n";
      return 0;
    }

    for(int i = 1; i <= n ; ++i) cout << color[i]+1 << ' ';
    cout << '\n';
    return 0;
}

