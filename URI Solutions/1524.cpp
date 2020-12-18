//https://www.urionlinejudge.com.br/judge/pt/problems/view/1524
//URI 1524 - Fila do Bandejão
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
    int n, k;
    while(scanf("%d%d", &n, &k)!=EOF){
      priority_queue<int, vector<int>, greater<int>> pq;
      pq.push(0);
      int last = 0;
      for(int i = 1; i < n ; ++i) {
        int x;
        scanf("%d", &x);
        pq.push(x-last);
        last = x;
      }
      int ans = 0;
      while(k++<=n){
        ans += pq.top();
        pq.pop();
      }
      printf("%d\n", ans);
    }
    return 0;
}