//https://www.urionlinejudge.com.br/judge/pt/problems/view/1054
//URI 1054 - Sapo Dinâmico
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> rocks;
int main(){
    int t, ti = 1, n, d;
    scanf("%d", &t);

    while(t--){
        scanf("%d%d", &n, &d);
        rocks.push_back(make_pair(1, 0));
        for(int i = 1; i <= n ; ++i) {
            char a;
            int c;
            scanf(" %c-%d", &a, &c);
            rocks.push_back(make_pair(a == 'B',c));
        }
        rocks.push_back(make_pair(1, d));

        int last = 0, ans = 0, k = 1;
        for(int i = 1; i <= n+1 ; ++i){
            if(rocks[i].first == 1){
                ans = max(ans, abs(rocks[i].second - last));
                last = rocks[i].second;
            }else if(rocks[i].first == 0){
                if(k){
                    rocks[i].first = -1;
                    ans = max(ans, abs(rocks[i].second - last));
                    last = rocks[i].second;
                }
                k = 1 - k;
            }
        }

        for(int i = n; i>=0; i--){
            if(rocks[i].first >= 0){
                ans = max(ans, abs(rocks[i].second - last));
                last = rocks[i].second;
            }
        }

        printf("Case %d: %d\n", ti++, ans);
        if(t) rocks.clear();
    }

    return 0;
}