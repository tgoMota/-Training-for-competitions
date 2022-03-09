//TIME LIMIT????? WHY
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
const int N = 40000;
seg segments[N];
int nxt[N], in[N], sum[N];
ii get_val(ii& a){
  if(a.second == 1) return {segments[a.first].l.x, segments[a.first].l.y}; //begin
  return {segments[a.first].r.x, segments[a.first].r.y}; //end
}

vector<ii> to_sweep;
set<int, bool(*)(int,int)> sweep([](int a, int b){
  if(segments[a].l.x <= segments[b].l.x) return cross(segments[a].l, segments[b].l, segments[a].r) < 0;
  return cross(segments[b].l, segments[a].l, segments[b].r) > 0;
});

bool is_aclive(seg a){
  return a.l.y < a.r.y;
}
bool is_declive(seg a){
  return a.l.y > a.r.y;
}

void solve(int i){
  if(nxt[i] == -1 || in[i] > 0) return;
  sum[nxt[i]] += sum[i];
  --in[nxt[i]];
  solve(nxt[i]);
}


int main(){
  fastio();
  int t;
  cin >> t;
  for(int ti = 1; ti <= t ; ++ti){
    int n;
    cin >> n;
    sweep.clear();
    to_sweep.clear();
    for(int i = 0; i < n ; ++i){
      cin >> segments[i].l.x >> segments[i].l.y >> segments[i].r.x >> segments[i].r.y;
      if(segments[i].l.x > segments[i].r.x) swap(segments[i].l, segments[i].r);
      to_sweep.push_back({i,1});
      to_sweep.push_back({i,2});
      in[i] = sum[i] = 0;
      nxt[i] = -1;
    }
    sort(all(to_sweep), [&](ii& a, ii& b){
      ii val_a = get_val(a);
      ii val_b = get_val(b);

      if(val_a.first == val_b.first){
        if(a.second == b.second) {
          if(a.second == 1) return val_a.second < val_b.second;
          return val_a.second > val_b.second;
        }
        return a.second < b.second;
      }
      return val_a.first < val_b.first;
    });

    auto get_below = [&](ii& x){
      auto it = sweep.upper_bound(x.first);
      return it == sweep.end() ? -1 : *it;
    };

    int cur_id = -1, cur_x = 0;
    for(ii& x : to_sweep){
      if(x.second == 1){
        sweep.insert(x.first);
        if(is_aclive(segments[x.first])){
          nxt[x.first] = get_below(x);
          if(nxt[x.first] != -1) in[nxt[x.first]]++;
        }
        int tp = *sweep.begin();
        if(tp != cur_id){
          if(cur_id != -1){
            sum[cur_id] += segments[tp].l.x - cur_x;
          }
          cur_x = segments[tp].l.x;
          cur_id = tp;
        }
      }else{
        if(is_declive(segments[x.first])){
          nxt[x.first] = get_below(x);
          if(nxt[x.first] != -1) in[nxt[x.first]]++;
        }
        sweep.erase(x.first);
        if(x.first == cur_id){
          sum[cur_id] += segments[cur_id].r.x-cur_x; 
          cur_x = segments[cur_id].r.x;
          if(!sweep.empty()) cur_id = *sweep.begin();
          else cur_id = -1;
        }
      }
    }

    for(int i = 0; i < n ; ++i) solve(i);
    for(int i = 0; i < n ; ++i) cout << sum[i] << '\n';
  }
  return 0;
}
