//https://www.urionlinejudge.com.br/judge/pt/problems/view/1023
//URI 1023 - Estiagem
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
const double EPS = 1e-9;
int main(){
    int n, ti = 0;
    while(scanf("%d", &n) && n){
      if(ti) printf("\n");
      ll totalP = 0LL, totalC = 0LL;
      vector<ll> byConsumed(250, 0);
      for(int i = 0; i < n ; ++i){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        totalP += a;
        totalC += b;
        byConsumed[b/a]+=a;
      }
      printf("Cidade# %d:\n", ++ti);
      int cnt = 0;
      for(int i = 0; i < 250 ; ++i){
        if(byConsumed[i] > 0) {
          if(cnt++) printf(" ");
          printf("%lld-%d", byConsumed[i], i);
        }
      }
      double intPart;
      int fracPart = (int)(modf(totalC/(double)totalP, &intPart)*100);
      if(fracPart>=10) printf("\nConsumo medio: %d.%d m3.\n",(int)intPart, fracPart);
      else printf("\nConsumo medio: %d.0%d m3.\n",(int)intPart, fracPart);
    }
    return 0;
}