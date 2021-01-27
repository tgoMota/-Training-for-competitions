//https://www.urionlinejudge.com.br/judge/pt/problems/view/2700
//URI 2700 - Angariando Fundos
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
int n;
vector<pair<ll,ii>> v;

struct Seg{
  vector<ll> t;
  Seg(const int n){
    t.assign(4*n, 0);
  }

  void update(int i, int l, int r, int p, ll x){
        if(l > r) return;
        if(l == r){
            t[i] = max(t[i], x);
            return;
        }
        int m = l + (r-l)/2;
        if(p <= m) update(2*i, l, m, p, x);
        else update(2*i+1, m+1, r, p, x);
        t[i] = max(t[2*i], t[2*i+1]);
    }

    ll query(int i, int l, int r, int ql, int qr){
        if(ql <= l && qr >= r) return t[i];
        if(ql > r || qr < l) return 0;
        int m = l + (r-l)/2;
        return max(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
    }

};

int main(){
    scanf("%d", &n);
    v.resize(n);
    map<ii,ll> compressed;
    set<int> onlyf;
    for(pair<ll,ii> &x : v) {
      scanf("%d%d%lld", &x.second.first, &x.second.second, &x.first);
      auto it = compressed.find(x.second);
      onlyf.insert(x.second.second);
      if(it == compressed.end()) compressed[x.second] = x.first;
      else it->second += x.first;
    }
    unordered_map<int,int> countf;
    int count = 0;
    for(int x : onlyf){
      countf[x] = count++;
    }
    vector<pair<ll,ii>> new_v;
    int idx = 0;
    for(auto x : compressed) {
      pair<ii, ll> y = x;
      y.first.second = countf[y.first.second];
      new_v.push_back({y.second, y.first});
    }
    const int N = (int)new_v.size();
    sort(new_v.begin(), new_v.end(), [](pair<ll,ii>& a, pair<ll,ii>& b){
      if(a.second.first != b.second.first) return a.second.first < b.second.first;
      return a.second.second > b.second.second;
    });

    Seg seg(N);
    for(auto x : new_v){
      ll before = seg.query(1, 0, N-1, 0, x.second.second-1);
     // trace(x.first);
      seg.update(1, 0, N-1, x.second.second, before+x.first);
    }

    ll ans = seg.query(1, 0, N-1, 0, N-1);

    printf("%lld\n", ans);
    return 0;
}
