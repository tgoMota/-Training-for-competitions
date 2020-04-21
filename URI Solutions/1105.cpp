//https://www.urionlinejudge.com.br/judge/pt/problems/view/1105
//URI 1105 - Sub-prime
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int b, n, k;
    vector<int> c;
    while(scanf("%d%d", &b, &n) && b+n){
        c.assign(b+1,0);
        for(int i = 1; i <= b ; ++i){
            scanf("%d", &k);
            c[i] = k;
        }

        for(int i = 0; i < n ; ++i){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            c[x] -= z;
            c[y] += z;
        }

        int ans = 1;
        for(int x : c){
            if(x < 0){
                ans = 0;
                break;
            }
        }

        printf("%c\n", ans? 'S':'N');
    }

    return 0;
}