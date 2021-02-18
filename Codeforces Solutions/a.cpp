//https://codeforces.com/contest/229/problem/B
//B. Planets
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
int n, m;
vector<vector<ii>> adj;
vector<vector<int>> arrives;
vector<int> dist;

int takeTime(int x, int timeLimit){
  if(x == n) return timeLimit;
  const int N = arrives[x][0];
  int lo = 1, hi = N+1;
  while(lo < hi){
    int mid = (lo + hi) >> 1;
    if(arrives[x][mid] >= timeLimit) hi = mid;
    else lo = mid+1;
  }
  if(lo == N+1 || arrives[x][lo] != timeLimit) return timeLimit;
  int ini = lo;
  hi = N+1;
  while(lo < hi){
    int mid = (lo + hi) >> 1;
    int dif = mid - ini;
    if(arrives[x][mid] > timeLimit+dif) hi = mid;
    else lo = mid+1;
  }
  return timeLimit+ lo-ini;
}

void dji(){
  dist.assign(n+1, oo);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  dist[1] = takeTime(1, 0);
  pq.push({dist[1], 1});
  while(!pq.empty()){
    auto X = pq.top();
    pq.pop();
    int v = X.second;
    int d = X.first;
    for(auto x : adj[v]){
      if(dist[v]+x.second < dist[x.first]){
        int timeArrive = takeTime(x.first, dist[v]+x.second);
        if(timeArrive>=dist[x.first]) continue;
        dist[x.first] = timeArrive;
        pq.push({dist[x.first], x.first});
      }
    }
  }
}

int main(){
    cin >> n >> m;
    adj.assign(n+1, vector<ii>());
    for(int i = 0; i < m ; ++i){
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b,c});
      adj[b].push_back({a,c});
    }
    
    arrives.assign(n+1, vector<int>());
    for(int i = 1; i <= n ; ++i){
      int a;
      cin >> a;
      arrives[i].push_back(a);
      for(int j = 0; j < arrives[i][0] ; ++j){
        cin >> a;
        arrives[i].push_back(a);
      }
    }

    dji();
    int ans = dist[n];
    if(ans == oo) ans = -1;
    cout << ans << '\n';

    return 0;
}
