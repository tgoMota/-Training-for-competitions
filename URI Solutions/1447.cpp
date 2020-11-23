//https://www.urionlinejudge.com.br/judge/pt/problems/view/1447
//URI 1447 - Back to the Future
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<vector<int>> cap, cost;
vector<int> dist;
int ide;
struct edge{
  int id,to, cost, cap;
  edge(){}
  edge(int _id, int _to, int _cost, int _cap){
    id = _id;
    to = _to;
    cost = _cost;
    cap = _cap;
  }
};

vector<vector<edge>> adj;
void augment(int v, int& flow, const int N, vector<int>& p){
  if(v == 1) return;
  else if(p[v] != -1){
    augment(p[v], flow = min(flow, cap[p[v]][v]), N, p);
    for(edge& e : adj[p[v]]){
      if(e.to == v) e.cap-=flow;
    }
    for(edge& e : adj[v]){
      if(e.to == p[v]) e.cap+=flow;
    }
    //cap[p[v]][v]-=flow;
    //cap[v][p[v]]+=flow;
  }
}


// bool dji(vector<int>& p, const int N){
//   p.assign(N+1, -1);
//   dist.assign(N+1, -1);
//   set<pair<int,ii>> s;
//   s.insert({0,{1,-1}});
//   while(!s.empty()){
//     auto x = *s.begin();
//     s.erase(s.begin());
//     int u = x.second.first;
//     int v = x.second.second;
//     int d = x.first;
//     if(dist[u] != -1) continue;
//     dist[u] = d;
//     p[u] = v;
//     if(u == N) return true;
//     for(int i = 1; i <= N ; ++i){
//       if(i == u || cap[u][i] <= 0 || dist[i] != -1) continue;
//       s.insert({d+cost[u][i],make_pair(i,u)});
//     }
//   }
//   return false;
// }

bool belmanFord(vector<int>& p, const int N){
  p.assign(N+1, -1);
  dist.assign(N+1, oo);
  vector<bool> inUse(N+1, false);
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while(!q.empty()){
    printf("na fila...\n");
    int u = q.front();
    q.pop();
    inUse[u] = false;
    for(edge& e : adj[u]){
      if(e.cap > 0 && dist[e.to] > dist[u]+e.cost){
        dist[e.to] = dist[u] + e.cost;
        p[e.to] = u;
        if(inUse[e.to]) continue;
        inUse[e.to] = true;
        q.push(e.to);
      }
    }
  }

  return dist[N] != oo;
}

int maxFlow(const int N, const int D){
  vector<int> p;
  int mxFlow = 0, totalCost = 0, remain = D;
  while(belmanFord(p, N)){
    int flow = oo;
    augment(N, flow, N, p);
    totalCost += min(remain, flow)*dist[N];
    remain-=flow;
    if(remain <= 0) return totalCost;
  }
  return -1;
}

int main(){
  int n, m, t = 0;
  ide = 0;
  while(scanf("%d%d", &n, &m) != EOF){
    cap.assign(n+1, vector<int>(n+1, 0));
    cost.assign(n+1, vector<int>(n+1, 0));
    adj.assign(n+1, vector<edge>());
    for(int i = 0; i < m ; ++i){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      adj[a].push_back(edge(ide++,b,c,0));
      adj[b].push_back(edge(ide++,a,c,0));
      adj[a].push_back(edge(ide++,b,-c,0));
      adj[b].push_back(edge(ide++,a,-c,0));
    }

    int d, k;
    scanf("%d%d", &d, &k);
    for(int i = 1; i <= n ; ++i){
      for(edge& e : adj[i]) e.cap = k;
    }

    int mxFlow = maxFlow(n,d);
    printf("Instancia %d\n", ++t);
    if(mxFlow == -1) printf("impossivel\n\n");
    else printf("%d\n\n", mxFlow);
  }

  return 0;
}