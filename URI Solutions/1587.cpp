//https://www.urionlinejudge.com.br/judge/pt/problems/view/1587
//URI 1587 - BIT Park
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int MAXN = 2000050;
typedef struct SegTree{
  vector<int> t, v;
  int goals;
  void init(){
    t.assign(4*MAXN, 0);
    v.assign(MAXN/2, 0);
    goals = 0;
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
      if(p <= m) update(2*i, l, m, p, val);
      else update(2*i+1, m+1, r, p, val);
      t[i] = t[2*i] + t[2*i+1];
    }
  }
}Seg;

pair<int,int> extractId(string& id){
  pair<int,int> a; //{team, id};
  a.first = id[0]-'A';
  id.erase(id.begin());
  a.second = strtol(id.c_str(), nullptr, 10);
  return a;
}

int main(){
  fastio();
  int n, e;
  Seg team[2];
  while(cin >> n >> e && n+e){
    for(int i = 0; i < 2 ; ++i){
      team[i].init();
      for(int j = 0; j < n/2 ; ++j){
        int a;
        cin >> a;
        team[i].v[j+1] = a;
        team[i].update(1,0,MAXN, a, 1);
      }
    }
    pair<int,int> ball;
    bool impediment = false;

    for(int i = 0; i < e ; ++i){
      string s;
      cin >> s;
      if(s == "I"){
        string id;
        cin >> id;
        impediment = false;
        pair<int,int> p = extractId(id);
        ball = p; //takes de ball
        int posp = team[p.first].v[p.second];
        int resultq;
        if(p.first == 0) resultq = team[p.first^1].query(1,0,MAXN, posp+1,MAXN);
        else resultq = team[p.first^1].query(1,0,MAXN, 0 , posp-1);
        
        if(resultq < n/(double)11) impediment = true;
      }else if(s == "M"){
        string player;
        cin >> player;
        pair<int,int> p = extractId(player);
        int newpos;
        cin >> newpos;
        team[p.first].update(1,0,MAXN, team[p.first].v[p.second], -1);
        team[p.first].update(1,0,MAXN,newpos, 1);
        team[p.first].v[p.second] = newpos;
      }else if(s == "P"){
        string player;
        cin >> player;
        if(impediment) continue;
        pair<int,int> p = extractId(player);
        ball = p; //takes de ball
        int posp = team[p.first].v[p.second];
        int resultq;
        if(p.first == 0) resultq = team[p.first^1].query(1,0,MAXN, posp+1,MAXN);
        else resultq = team[p.first^1].query(1,0,MAXN, 0 , posp-1);
        if(resultq < n/(double)11) impediment = true;
      }else if(s == "G"){
        string player;
        cin >> player;
        int enemy = ((player[0]-'A')+1)%2;
        if(!impediment) team[enemy].goals++;
        impediment = false;
      }else if(s == "S"){
        impediment = false;      
      }
    }
    cout << team[0].goals << " X " << team[1].goals << '\n';
  }

  return 0;
}