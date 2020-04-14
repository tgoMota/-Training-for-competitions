//https://www.urionlinejudge.com.br/judge/pt/problems/view/1104
//URI 1104 - Troca de Cartas

#include <bits/stdc++.h>
using namespace std;

int main(){

    int na, nb, k;
    vector<int> a, b;
    while(scanf("%d%d", &na, &nb) && na+nb){
        a.clear(); b.clear();
        for(int i = 0; i < na ; ++i){
            scanf("%d", &k);
            if(i && k == a.back()) continue;
            a.push_back(k);
        }
        for(int i = 0; i < nb ; ++i){
            scanf("%d", &k);
            if(i && k == b.back()) continue;
            b.push_back(k);
        }
        int maxexchange = min(a.size(), b.size());
        for(int x : a){
            if(binary_search(b.begin(), b.end(), x)) maxexchange--;
        }

        printf("%d\n", maxexchange);

    }

    return 0;
}