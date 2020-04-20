//https://www.urionlinejudge.com.br/judge/pt/problems/view/2126
//URI 2126 - Procurando Subsequências
#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    int t = 0;
    while(cin >> a >> b){
        int ans = 0, last = 0;
        for(int i = 0; i < b.size() ; ++i){
            if(b[i] == a[0]){
                bool ok = true;
                int j, k;
                for(j = 0, k = i; j < a.size() && k < b.size() ; ++j, ++k){
                    if(a[j] != b[k]) {
                        ok = false;
                        break;
                    }
                }
                if(ok && j == a.size()){
                    ans++;
                    last = i;
                }
            }
        }

        printf("Caso #%d:\n", ++t);
        if(ans){
            printf("Qtd.Subsequencias: %d\n", ans);
            printf("Pos: %d\n", ++last);
        }else printf("Nao existe subsequencia\n");
        printf("\n");
    }
    return 0;
}