//https://www.urionlinejudge.com.br/judge/pt/problems/view/1500
//URI 1500 - Consultas Horríveis
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

struct Seg{
  vector<ll> t, lz;
  Seg(const int N){
    t.assign(4*N, 0LL);
    lz.assign(4*N, 0LL);
  }
  void down(int idx, int l, int r){
    if(lz[idx]){
      int left = 2*idx, right = 2*idx+1;
      t[idx]+=lz[idx]*(r-l+1);
      if(l != r){
        lz[left]+=lz[idx];
        lz[right]+=lz[idx];
      }
    }
    lz[idx] = 0;
  }
  void update(int idx, int l, int r, int ql, int qr, int v){
    down(idx, l, r);
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr){
      lz[idx] += v;
      down(idx, l, r);
      return;
    }
    int mid = (l+r)>>1;
    update(2*idx, l, mid, ql, qr, v);
    update(2*idx+1, mid+1, r, ql, qr, v);
    t[idx] = t[2*idx] + t[2*idx+1];
  }

  ll query(int idx, int l, int r, int ql, int qr){
    down(idx, l, r);
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return t[idx];
    int mid = (l+r)>>1;
    return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
  }
};

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, c;
        scanf("%d%d", &n, &c);
        Seg seg(n+10);
        while(c--){
          int type;
          scanf("%d", &type);
          if(type){
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%lld\n", seg.query(1,0,n, a, b));
          }else{
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            seg.update(1,0,n,a,b,c);
          }
        }
    }
    return 0;
}
