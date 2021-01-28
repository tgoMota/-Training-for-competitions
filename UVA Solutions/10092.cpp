//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1033
//UVA 10092 - The Problem with the Problem Setter
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
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
//CHECK THE LIMITS, PLEASE
const int NAX = 1050;
int nk, np, sink, dest;
int parent[NAX];
vector<map<int,int>> list_adj;

void aug(int v){
  if(parent[v] == -1) return;
  list_adj[parent[v]][v]--;
  list_adj[v][parent[v]]++;
  aug(parent[v]);
}

bool bfs(){
  vector<bool> vst(NAX, false);
  memset(parent, -1, sizeof(parent));
  queue<int> q;
  q.push(sink);
  vst[sink] = true;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    if(v == dest) break;
    for(auto it : list_adj[v]){
      int i = it.first, w = it.second;
      if(!vst[i] && w > 0){
        vst[i] = true;
        parent[i] = v;
        q.push(i);
      }
    }
  }

  return vst[dest];
}

int maxflow(){
  int mxflow = 0;
  while(bfs()){
    mxflow++;
    aug(dest);
  }
  return mxflow;
}


int main(){
    while(scanf("%d%d", &nk, &np) && nk+np){
      sink = 0, dest = nk+np+1;
      list_adj.assign(NAX, map<int,int>());
      int sum = 0;
      for(int i = 1; i <= nk ; ++i){
        int a;
        scanf("%d", &a);
        list_adj[sink][i] = a;
        sum += a;
      }
      for(int p = nk+1; p <= nk+np ; ++p){
        int t;
        scanf("%d", &t);
        for(int j = 0; j < t ; ++j){
          int category;
          scanf("%d", &category);
          list_adj[category][p] = 1;
        }
        list_adj[p][dest] = 1;
      }

      int ans = maxflow();
      if(ans != sum){
        printf("0\n");
        continue;
      }
      printf("1\n");
      for(int i = 1; i <= nk ; ++i){
        for(auto x : list_adj[i]){
          if(x.second == 0){
            printf("%d ", x.first-nk);
          }
        }
        printf("\n");
      }
    }
    return 0;
}