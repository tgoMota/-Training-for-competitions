//https://www.urionlinejudge.com.br/judge/pt/problems/view/2784
//URI 2784 - Ilhas
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<vector<ii>> adj;
vector<int> dist;

void dji(int s, const int N, const int M){
  dist.assign(N+1, oo);
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0,s});
  dist[s] = 0;
  vector<bool> inq(N+1, false);
  while(!pq.empty()){
    auto x = pq.top();
    pq.pop();
    int u = x.second;
    int ds = x.first;
    inq[u] = true;
    for(auto x : adj[u]){
      int v = x.first;
      int w = x.second;
      if(u == v || inq[v] || dist[u]+w >= dist[v]) continue;
      pq.push({ds+w, v});
      dist[v] = ds+w;
    }
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  adj.assign(n+1, vector<ii>());
  for(int i = 0; i < m ; ++i){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }

  int s;
  scanf("%d", &s);
  dji(s, n, m);
  int mind = oo, maxd = -oo;
  for(int i = 1; i <= n ; ++i){
    if(i ==  s) continue;
    mind = min(mind, dist[i]);
    maxd = max(maxd, dist[i]);
  }

  printf("%d\n", maxd-mind);

  return 0;
}