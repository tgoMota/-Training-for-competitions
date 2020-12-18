//https://www.urionlinejudge.com.br/judge/pt/problems/view/2115
//URI 2115 - Produção em Ecaterimburgo
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
    vector<ii> v;
    while(scanf("%d", &n) != EOF){
      v.clear();
      for(int i = 0; i < n ; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back({a,b});
      }
      sort(v.begin(), v.end());
      int cur = 1;
      for(int i = 0; i < n ; ++i){
        if(cur >= v[i].first) cur+=v[i].second;
        else cur = v[i].first + v[i].second;
      }

      printf("%d\n", cur);
    }
    return 0;
}