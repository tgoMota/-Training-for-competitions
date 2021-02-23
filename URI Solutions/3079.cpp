//https://www.urionlinejudge.com.br/judge/pt/problems/view/3079
//URI 3079 - Rua Iluminada
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//CHECK THE LIMITS, PLEASE
int N, M;
vector<int> v;

struct Seg{
  vector<int> t, lz;
  Seg(){}
  Seg(const int n){
    t.assign(4*n, 0);
    lz.assign(4*n, 0);
  }

  void push(int i, int l, int r){
    if(lz[i]){
      t[i] += lz[i];
      if(l != r){
        lz[2*i] += lz[i];
        lz[2*i+1] += lz[i];
      }
      lz[i] = 0;
    }
  }

  void update(int i, int l, int r, int ql, int qr, int x){
    push(i,l,r);
    if(ql > r || qr < l) return;
    if(ql <= l && qr >= r){
      lz[i] += x;
      push(i, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(2*i, l, m, ql, qr, x);
    update(2*i+1, m+1, r, ql, qr, x);
    t[i] = max(t[2*i], t[2*i+1]);
  }

  int query(int i, int l, int r, int ql, int qr){
    push(i, l, r);
    if(ql > r || qr < l) return -oo;
    if(ql <= l && qr >= r) return t[i];
    int m = (l + r) >> 1;
    return max(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
  }
};

Seg st;
bool can(int k){
  st = Seg(k);
  for(int i = 0; i < N ; ++i){
    int dif = v[i+1]-v[i];
    int a = v[i] % k;
    int b = (v[i+1]-1) % k;
    if(k <= dif) st.update(1, 0, k-1, 0, k-1, 1);
    else if(a > b){
      st.update(1, 0, k-1, a, k-1, 1);
      st.update(1, 0, k-1, 0, b, 1);
    }else{
      st.update(1, 0, k-1, a, b, 1);
    }
  }
  int ans = st.query(1, 0, k-1, 0, k-1);
  return ans == N;
}
int main(){
    fastio();
    cin >> N >> M;
    v.resize(N+1);
    for(int i = 0; i < N ; ++i){
      cin >> v[i];
    }
    v[N] = M+1;
    int ans = 1;
    for(int i = (N+M-2)/(N-1); i > 1; i--){
      if(can(i)){
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
    return 0;
}
