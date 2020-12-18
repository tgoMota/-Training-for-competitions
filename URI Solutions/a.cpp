//https://www.urionlinejudge.com.br/judge/pt/problems/view/1661
//URI1661 - Comércio de Vinhos na Gergóvia
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
 
int main(){
    int n;
    while(scanf("%d", &n) && n){
      vector<ll> v(n+1);
      ll ans = 0LL;
      for(int i = 1; i <= n ; ++i){
        scanf("%lld", &v[i]);
        v[i]+=v[i-1];
        ans += abs(v[i]);
      }

      printf("%lld\n", ans);
    }
    return 0;
}