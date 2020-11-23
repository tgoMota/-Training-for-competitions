//https://www.urionlinejudge.com.br/judge/pt/problems/view/2380
//URI 2380 - Fusões
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
vector<int> p;

int find(int u){
  return p[u] == u ? u : find(p[u]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);
  p[v] = u;
}

bool isSameSet(int u, int v){
  return find(u) == find(v);
}

int main(){
  fastio();
  int N, Q;
  cin >> N >> Q;
  p.resize(N);
  for(int i = 0; i < N ; ++i) p[i] = i;
  for(int i = 0; i < Q ; ++i){
    string c;
    int A, B;
    cin >> c >> A >> B;
    if(c == "C") cout << (isSameSet(A-1, B-1)?'S':'N') << '\n';
    else merge(A-1, B-1);
  }

  return 0;
}