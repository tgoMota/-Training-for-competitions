//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761
//UVA 820 - Internet Bandwidth
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
//CHECK THE LIMITS, PLEASE
const int MX = 105;
int res[MX][MX], N, S, T, C, parent[MX];

int augmentPath(int v, int minflow){
  if(parent[v] == -1) return minflow;
  minflow = augmentPath(parent[v], min(minflow, res[parent[v]][v]));
  res[parent[v]][v] -= minflow;
  res[v][parent[v]] += minflow;
  return minflow;
}

bool bfs(){
  queue<int> q;
  bool vst[MX];
  memset(vst, false, sizeof(vst));
  memset(parent, -1, sizeof(parent));
  q.push(S);
  vst[S] = true;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int i = 1; i <= N ; ++i){
      if(!vst[i] && res[v][i] > 0){
        q.push(i);
        parent[i] = v;
        vst[i] = true;
      }
    }
  }
  return vst[T];
}

int maxflow(){
  int maxflow = 0;
  while(bfs()){
    int flow = augmentPath(T, oo);
    maxflow += flow;
  }
  return maxflow;
}

int main(){
    int ti = 0;
    while(scanf("%d", &N) && N){
      memset(res, 0, sizeof(res));
      scanf("%d%d%d", &S, &T, &C);
      for(int i = 0; i < C ; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        res[a][b] += c;
        res[b][a] += c;
      }

      printf("Network %d\n",++ti);
      printf("The bandwidth is %d.\n\n", maxflow());
    }
    return 0;
}
