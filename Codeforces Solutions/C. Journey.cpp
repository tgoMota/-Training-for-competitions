//https://codeforces.com/problemset/problem/839/C
//C. Journey
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
int N;
vector<vector<int>> adj;

double dfs(int v, int p, int xi, double pi){
  bool isLeaf = true;
  double ans = 0.0;
  for(int x : adj[v]){
    if(x != p){
      isLeaf = false;
      ans+=dfs(x, v, xi+1, pi/(adj[v].size()-(v!=1))); 
    }
  }
  return isLeaf ? xi*pi : ans;
}
int main(){
    fastio();
    cout << fixed << setprecision(10);
    cin >> N;
    adj.assign(N+1, vector<int>());
    for(int i = 0; i < N-1 ; ++i){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    cout << dfs(1,1,0,1) << '\n';
    return 0;
}
