//https://www.urionlinejudge.com.br/judge/pt/problems/view/2185
//URI 2185 - Brincando com Pomekons
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
const int N = 1e5+5;
typedef struct SegTree{
  vector<int> t, lz, v;
  void init(int n){
    t.assign(4*N, 0);
    lz.assign(4*N, -1);
    build(1, 0, n-1);
  }

  void push(int i, int l, int r){
    if(lz[i] == -1) return;
    if((r-l+1)%2 == 0) t[i] = 0;
    else  t[i] = lz[i];
    
    if(l != r) lz[2*i] = lz[2*i+1] = lz[i];
    lz[i] = -1;
  }

  void build(int i, int l, int r){
    if(l == r) t[i] = v[l];
    else{
      int m = (l+r)>>1;
      build(2*i, l, m);
      build(2*i+1, m+1, r);
      t[i] = t[2*i]^t[2*i+1];
    }
  }

  int query(int i, int l, int r, int ql, int qr){
    push(i, l, r);
    if(ql > r || qr < l) return 0;
    if(ql <= l && qr >= r) return t[i];
    int m = (l+r)>>1;
    return query(2*i, l, m, ql, qr)^query(2*i+1, m+1, r, ql, qr);
  }

  void update(int i, int l, int r, int ql, int qr, int x){
    push(i, l, r);
    if(ql > r || qr < l) return;
    if(ql <= l && qr >= r){
      if((r-l+1)%2 == 0) t[i] = 0;
      else t[i] = x;

      if(l != r) lz[2*i] = lz[2*i+1] = x;
      return;
    }
    int m = (l+r)>>1;
    update(2*i, l, m, ql, qr, x);
    update(2*i+1, m+1, r, ql, qr, x);
    t[i] = t[2*i]^t[2*i+1];
  }
}Seg;

int main(){
  int n, e;
  scanf("%d%d", &n, &e);
  Seg st;
  st.v.assign(n, 0);
  for(int i = 0; i < n ; ++i) scanf("%d", &st.v[i]);
  st.init(n);
  for(int i = 0; i < e ; ++i){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    st.update(1, 0, n-1, a-1, b-1, c);
    printf("%s\n", st.query(1, 0, n-1, 0, n-1)? "Possivel" : "Impossivel");
  }
  return 0;
}