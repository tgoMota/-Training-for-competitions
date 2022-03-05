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
int N, Q;
vector<vector<int>> adj1, adj2;
vector<int> hs, h1, h2;
vector<ll> pref;
int diameter1, diameter2, max_diameter;
pair<ii,int> getDiameter(vector<vector<int>>& adj){
  const int sz = (int)adj.size();
  vector<int> dist(sz+1, -1);
  queue<ii> q;
  ii mx_d = {1,0};
  q.push(mx_d);
  while(!q.empty()){
    auto x = q.front();
    q.pop();
    int v = x.first;
    int d = x.second;
    dist[v] = d;
    if(d > mx_d.second){
      mx_d = x;
    }
    for(int u : adj[v]){
      if(dist[u] != -1) continue;
      q.push({u, d+1});
    }
  }

  int bottom = mx_d.first;
  mx_d.second = 0;
  q.push(mx_d);
  dist.assign(sz+1, -1);
  while(!q.empty()){
    auto x = q.front();
    q.pop();
    int v = x.first;
    int d = x.second;
    dist[v] = d;
    if(d > mx_d.second){
      mx_d = x;
    }
    for(int u : adj[v]){
      if(dist[u] != -1) continue;
      q.push({u, d+1});
    }
  }
  
  return {{bottom, mx_d.first}, mx_d.second};
}

void dfs_dist(int v, int p, int d, vector<int>& h, vector<vector<int>>& adj){
  h[v] = max(h[v], d);
  for(int x : adj[v]){
    if(x == p) continue;
    dfs_dist(x, v, d+1, h, adj);
  }
}

int main(){
    fastio();
    while(cin >> N >> Q){
      adj1.assign(N+1, vector<int>());
      adj2.assign(Q+1, vector<int>());
      h1.assign(N+1, 0);
      h2.assign(Q+1, 0);
      hs.clear();
      pref.clear();

      for(int i = 0; i < N-1 ; ++i){
        int a, b;
        cin >> a >> b;
        adj1[a].push_back(b);
        adj1[b].push_back(a);
      }

      for(int i = 0; i < Q-1 ; ++i){
        int a, b;
        cin >> a >> b;
        adj2[a].push_back(b);
        adj2[b].push_back(a);
      }
      pair<ii,int> A = getDiameter(adj1);
      pair<ii,int> B = getDiameter(adj2);
      diameter1 = A.second;
      diameter2 = B.second;
      
      max_diameter = max(diameter1, diameter2);
      dfs_dist(A.first.first, -1, 0, h1, adj1);
      dfs_dist(A.first.second, -1, 0, h1, adj1);
      dfs_dist(B.first.first, -1, 0, h2, adj2);
      dfs_dist(B.first.second, -1, 0, h2, adj2);
      for(int i = 1; i <= Q ; ++i) hs.push_back(h2[i]);
      sort(hs.begin(), hs.end()); //hs of adj2
      ll sum = 0;
      for(int i = 0; i < (int)hs.size() ; ++i){
        sum += hs[i];
        pref.push_back(sum);
      }

      auto get = [&](int a, int b){
        if(a == 0) return pref[b];
        return pref[b]-pref[a-1];
      };
      
      ll ans = 0;
      for(int i = 1; i <= N ; ++i){
        int lo = 0, hi = Q;
        while(lo < hi){
          int mid = (lo + hi) >> 1;
          if(h1[i] + hs[mid]+1 > max_diameter) hi = mid;
          else lo = mid+1;
        }
        ans += lo*max_diameter;
        ans += (Q-lo)*(h1[i]+1)+ get(lo, Q-1);
        
      }
      cout << fixed << setprecision(3) << ans/double(N*Q) << '\n';
    }
    return 0;
}
