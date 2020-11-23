//https://www.urionlinejudge.com.br/judge/pt/problems/view/1579
//URI 1579 - Transporte de Painéis Solares
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int n, c, f;
vector<int> v;
typedef long long ll;

bool check(int x, int& mxsum, const int N, const int C){
  int sum = 0, ntrucks = 1;
  mxsum = -oo;
  for(int i = 0; i < N ; ++i){
    if(sum+v[i] > x){
      ntrucks++;
      sum = 0;
    }
    sum+=v[i];
    mxsum = max(mxsum, sum);
  }
  return ntrucks > C;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d%d", &n, &c, &f);
    v.assign(n, 0);
    int sum = 0;
    for(int& x : v) {
      scanf("%d", &x);
      sum+=x;
    }
    int lo = 0, hi = sum, ans;
    while(lo < hi){
      int mid = (lo+hi)>>1;
      if(check(mid, ans, n, c)) lo = mid+1;
      else hi = mid;
    }
    check(lo, ans, n, c);
    printf("%d $%d\n",ans, ans*c*f);
  }

  return 0;
}