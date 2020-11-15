//https://www.urionlinejudge.com.br/judge/pt/problems/view/2440
//URI 2440 - Famílias de Troia
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vst;

void dfs(int u){
  if(vst[u]) return;
  vst[u] = true;
  for(int x: adj[u]) dfs(x);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  adj.assign(n+1, vector<int>());
  vst.assign(n+1, false);
  for(int i = 0; i < m ; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = 0;
  for(int i = 1; i <= n ; ++i){
    if(!vst[i]){
      ans++;
      dfs(i);
    }
  }
  printf("%d\n", ans);


  return 0;
}