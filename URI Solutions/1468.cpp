//https://www.beecrowd.com.br/judge/pt/problems/view/1468
//URI 1468 - Balao
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(),(x).end()
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
//CHECK THE CONSTRAINTS, PLEASE
struct point{
    int x, y;
    point(){};
    point(int _x, int _y){ x = _x; y = _y; }
};

ll cross(point a, point b, point c){
  ll dx1 = a.x - b.x, dx2 = c.x - b.x;
  ll dy1 = a.y - b.y, dy2 = c.y - b.y;
  return dx1*dy2 - dx2*dy1;
}

struct seg{
    point l, r;
    seg(){};
    seg(point a, point b){ l = a; r = b; }
};
vector<seg> segments;
vector<int> querys;
int get_val(ii a){
  if(a.second == 1) return segments[a.first].l.x; //begin
  else if(a.second == 3) return segments[a.first].r.x; //end
  return querys[a.first]; //query
}
vector<ii> to_sweep;

set<int, bool(*)(int,int)> sweep([](int a, int b){
  if(segments[a].l.x < segments[b].l.x) return cross(segments[a].l, segments[b].l, segments[a].r) > 0;
  return cross(segments[b].l, segments[a].l, segments[b].r) < 0;
});
vector<int> nxt, first_to_take;
bool is_aclive(seg a){
  return a.l.y < a.r.y;
}
bool is_declive(seg a){
  return a.l.y > a.r.y;
}
vector<point> dp;
point solve(int i, int x){
  if(i == -1) return point(x,-1);
  if(nxt[i] == i) return {x,segments[i].l.y};
  point& ans = dp[i];
  if(ans.x  != -1) return ans;
  int nxt_x = is_aclive(segments[i]) ? segments[i].r.x : segments[i].l.x;
  return ans = solve(nxt[i], nxt_x);
} 

int main(){
  fastio();
  int n, q;
  while(cin >> n >> q){
    querys.resize(q);
    first_to_take.assign(q, -1);
    nxt.resize(n);
    segments.resize(n);
    sweep.clear();
    to_sweep.clear();
    for(int i = 0; i < n ; ++i){
      cin >> segments[i].l.x >> segments[i].l.y >> segments[i].r.x >> segments[i].r.y;
      if(segments[i].l.x > segments[i].r.x) swap(segments[i].l, segments[i].r);
      to_sweep.push_back({i,1});
      to_sweep.push_back({i,3});
      nxt[i] = i;
    }
    for(int i = 0; i < q ; ++i){
      cin >> querys[i];
      to_sweep.push_back({i,2});
    }

    sort(all(to_sweep), [&](ii& a, ii& b){
      int val_a = get_val(a), val_b = get_val(b);
      if(val_a == val_b) return a.second < b.second;
      return val_a < val_b;
    });
    auto get_above = [&](ii x){
      if(x.second == 2) return sweep.empty() ? -1 : *sweep.begin();
      auto it = sweep.upper_bound(x.first);
      return it == sweep.end() ? -1 : *it;
    };

    for(ii& x : to_sweep){
      if(x.second == 1){
        sweep.insert(x.first);
        if(is_declive(segments[x.first])) nxt[x.first] = get_above(x);
      }
      else if(x.second == 2){
        first_to_take[x.first] = get_above(x);
      }
      else if(x.second == 3){
        if(is_aclive(segments[x.first])) nxt[x.first] = get_above(x);
        sweep.erase(x.first);
      }
    }

    dp.assign(n, {-1,-1});
    for(int i = 0; i < q ; ++i){
      point ans = solve(first_to_take[i], querys[i]);
      cout << ans.x;
      if(ans.y != -1) cout << ' ' << ans.y;
      cout << '\n';
    }
  }
  return 0;
}
