//https://www.urionlinejudge.com.br/judge/pt/problems/view/2775
//URI 2775 - Preparando a Produção
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, sum, end;
    vector<pair<int,int>> v;
    while(scanf("%d", &n) != EOF){
        v.assign(n,{0,0});
        for(auto& x : v) scanf("%d", &x.first);
        for(auto& x : v) scanf("%d", &x.second);
        sum=0, end = n;
        bool swaped = false;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < end-1 ; ++j){
                if(v[j].first > v[j+1].first) {
                    sum+= v[j].second + v[j+1].second;
                    swap(v[j], v[j+1]);
                    swaped = true;
                }
            }
            if(!swaped) break;
            end--;    
        }
        printf("%d\n", sum);
    }

    return 0;
}