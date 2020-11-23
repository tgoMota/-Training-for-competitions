//https://www.urionlinejudge.com.br/judge/pt/problems/view/1587
//URI 1587 - BIT Park
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int MAXN = 2000005;
typedef struct SegTree{
  int t[4*MAXN];
  void init(){
    memset(t, 0, sizeof(t));
  }

  int query(int i, int l, int r, int ql, int qr){
    if (ql <= l && r <= qr) return t[i];
  	if (qr < l || r < ql) return 0;
    int m = (l+r)>>1;
    return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
  }

  void update(int i, int l, int r, int p, int val){
    if(l == r) t[i] += val;
    else{
      int m = (l+r)>>1;
      if(p <= m) update(2*i, l, m, val);
      else update(2*i+1, m+1, r, val);
      t[i] = t[2*i] + t[2*i+1];
    }
  }
}Seg;

bool isLegal(Seg& s, int idx, int team){
  if(s.query(1,1,MAXN,))
}

pair<int,int> extractId(string& id){
  pair<int,int> a; //{team, id};
  if(id[0] == 'A') a.first = 0;
  else a.first = 1;
  id.erase(id.begin());
  a.second = strtol(id, nullptr, 10);
  return a;
}

int main(){
  int n, e;
  fastio();
  Seg team[2];
  for(int i = 0; i < 2 ; ++i) team[i].init();
  for(int i = 0; i < 2 ; ++i){
    for(int j = 0; j < n/2 ; ++j){
      int a;
      cin >> a;
      team[i].update(1,1,MAXN, a, 1);
    }
  }

  for(int i = 0; i < e ; ++i){
    string s;
    cin >> s;
    if(s == "I"){
      string id;
      cin >> id;
      pair<int,int> p = extractId(id);

    }
  }




  return 0;
}