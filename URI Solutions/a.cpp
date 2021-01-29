//https://www.urionlinejudge.com.br/judge/pt/problems/view/1447
//URI 1447 - Back to the Future
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
int n, m, s, t, d, k;
vector<unordered_map<int, pair<ll,int>>> adj;
vector<ll> dist;
vector<int> parent;

int aug(int v, int mined){
  if(parent[v] == -1) return mined;
  mined = aug(parent[v], min(mined, adj[parent[v]][v].second));
  adj[parent[v]][v].second -= mined;
  adj[v][parent[v]].second += mined;
  adj[v][parent[v]].first = -adj[parent[v]][v].first;
  return mined;
}

bool belmanFord(){
  parent.assign(n+1, -1);
  dist.assign(n+1, oo);
  queue<int> q;
  vector<bool> inq(n+1, false);
  q.push(s);
  dist[s] = 0;
  while(!q.empty()){
    int v = q.front();
    inq[v] = false;
    q.pop();
    for(auto e : adj[v]){
      int u = e.first, w = e.second.first, cap = e.second.second;
      if(cap > 0 && dist[v]+w < dist[u]){
        dist[u] = dist[v]+w;
        parent[u] = v;
        if(!inq[u]){
          inq[u] = true;
          q.push(u);
        }
      }
    }
  }
  return dist[t] != oo;
}

pair<int,ll> maxflow(){
  int mxflow = 0;
  ll cost = 0LL;
  while(belmanFord()){
    int flow = aug(t, oo);
    mxflow += flow;
    cost += dist[t] * flow;
    if(mxflow >= d){
      int rest = mxflow-d;
      cost -= rest*dist[t];
      break;
    }
  }

  return {mxflow, cost};
}

int main(){
    int ti = 0;
    while(scanf("%d%d", &n, &m) != EOF){
      adj.assign(n+1, unordered_map<int,pair<ll,int>>());
      s = 1, t = n;
      for(int i = 0; i < m ; ++i){
        int a, b;
        ll c;
        scanf("%d%d%lld", &a, &b, &c);
        adj[a][b] = {c, 0};
        adj[b][a] = {c, 0};
      }
      scanf("%d%d", &d, &k);
      for(int i = 1; i <= n ; ++i){
        for(auto &e : adj[i]){
          e.second.second = k;
        }
      }
      printf("Instancia %d\n", ++ti);
      pair<ll,int> flowAndCost = maxflow();
      int flow = flowAndCost.first;
      ll cost = flowAndCost.second;
      if(flow < d) printf("impossivel\n");
      else printf("%lld\n", cost);
      printf("\n");
    }
    return 0;
}
