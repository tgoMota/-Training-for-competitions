//https://codeforces.com/contest/1468/problem/C
//C. Berpizza
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
const int N = 500000+5;

ii maxP(ii a, ii b){
  if(a.second == b.second) return (a.first < b.first ? a : b);
  return (a.second < b.second ? b : a);
}

ii minP(ii a, ii b){
  return (a.first < b.first ? a : b);
}

struct SegMax{
  vector<ii> t;
  SegMax(const int n){
    t.assign(4*n, {oo, 0}); //pos, money
  }

  void update(int i, int l, int r, int p, int x){
    if(l > r) return;
    if(l == r){
      t[i] = {l, x};
      return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(2*i, l, m, p, x);
    else update(2*i+1, m+1, r, p, x);
    t[i] = maxP(t[2*i], t[2*i+1]);
  }

  ii query(int i, int l, int r, int ql, int qr){
    if(ql >= l && qr <= r) return t[i];
    if(ql > r || qr < l) return {oo, 0};
    int m = (l + r) >> 1;
    return maxP(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
  }
}; 

struct SegMin{
  vector<ii> t;
  SegMin(const int n){
    t.assign(4*n, {oo,oo});
  }

  void update(int i, int l, int r, int p, int x){
    if(l > r) return;
    if(l == r){
      t[i] = {x, x};
      return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(2*i, l, m, p, x);
    else update(2*i+1, m+1, r, p, x);
    t[i] = minP(t[2*i], t[2*i+1]);
  }

  ii query(int i, int l, int r, int ql, int qr){
    if(ql >= l && qr <= r) return t[i];
    if(ql > r || qr < l) return {oo, oo};
    int m = (l + r) >> 1;
    return minP(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
  }
  
};

int main(){
    fastio();
    int t;
    cin >> t;
    SegMax A(N);
    SegMin B(N);
    int id = 0;
    for(int ti = 1; ti <= t ; ++ti){
        int a, b;
        cin >> a;
        if(a == 1){
          cin >> b;
          A.update(1,0,N-1,id, b);
          B.update(1,0,N-1,id, id);
          id++;
        }
        else if(a == 2){
          ii r = B.query(1, 0, N-1, 0, N-1);
          //trace(a, r.first+1, r.second);
          cout << r.first+1 << '\n';
          B.update(1, 0, N-1, r.first, oo);
          A.update(1, 0, N-1, r.first, 0);
        }
        else{
          ii r = A.query(1, 0, N-1, 0, N-1);
          //trace(a, r.first+1, r.second);
          cout << r.first+1 << '\n';
          B.update(1, 0, N-1, r.first, oo);
          A.update(1, 0, N-1, r.first, 0);
        }
    }
    return 0;
}
