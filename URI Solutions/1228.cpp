//https://www.urionlinejudge.com.br/judge/pt/problems/view/1228
//URI 1228 - Grid de Largada
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> posIni, order;
    int n;
    while(scanf("%d", &n) != EOF){
        posIni.resize(n+1);
        for(int i = 0; i < n ; ++i){
            int a;
            scanf("%d", &a);
            posIni[a] = i;
        }
        order.resize(n+1);
        for(int i = 0; i < n ; ++i){
            int a;
            scanf("%d", &a);
            order[i] = posIni[a];
        }
        int ans = 0;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < n-1 ; ++j){
                if(order[j] > order[j+1]){
                    ans++;
                    swap(order[j], order[j+1]);
                }
            }
        }
        printf("%d\n", ans);
    }
  
  return 0;
}