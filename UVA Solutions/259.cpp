//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=195
//UVA 259 - Software Allocation
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
vector<unordered_map<int,int>> adj;
vector<int> parent;
const int NAX = 51;
int s, t;
int idxapp = 1, idxpc = 27, napps = 0, totalusers = 0;
void reset(){
  adj.assign(NAX, unordered_map<int,int>());
  s = 0, t = 50;
  idxapp = 1, idxpc = 27, napps = 0, totalusers = 0;
}

void aug(int v){
  if(parent[v] == -1) return;
  adj[parent[v]][v]--;
  adj[v][parent[v]]++;
  aug(parent[v]);
}

bool bfs(){
  vector<bool> vst(NAX, false);
  parent.assign(NAX, -1);
  queue<int> q;
  q.push(s);
  vst[s] = true;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto it : adj[v]){
      if(!vst[it.first] && adj[v][it.first] > 0){
        parent[it.first] = v;
        vst[it.first] = true;
        q.push(it.first);
      }
    }
  }
  return vst[t];
}

int maxflow(){
  int mxflow = 0;
  while(bfs()){
    mxflow++;
    aug(t);
  }
  return mxflow;
}

void print(){
  int mxflow = maxflow();
  if(mxflow != totalusers){
    printf("!\n");
  }else{
    string ans(10, '_');
    for(int i = idxapp; i < idxpc ;  ++i){
      for(auto x : adj[i]){
        if(x.second == 0){
          char id_app = 'A' + (i-idxapp);
          int id_pc =  x.first-idxpc;
          ans[id_pc] = id_app;
        }
      }
    }
    printf("%s\n", ans.c_str());
  }
}

int main(){
    string line;
    reset();
    while(1){
      if(!getline(cin, line)){
        print();
        break;
      }
      if(line.empty()){
        print();
        reset();
        continue;
      }
      stringstream ss(line);
      string token;
      while(getline(ss, token, ' ')){
        int app, nusers;
        if(isalpha(token[0])){
          app = token[0]-'A'+1;
          napps++;
          nusers = token[1]-'0';
          totalusers += nusers;
          adj[s][app] = nusers;
        }else{
          for(char c : token){
            if(c == ';') break;
            int id_pc = c-'0'+idxpc;
            adj[app][id_pc] = 1;
            adj[id_pc][t] = 1;
          }
        }
      }

    }
    return 0;
}
