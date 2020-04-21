//https://www.urionlinejudge.com.br/judge/pt/problems/view/1103
//URI 1103 - Alarme Despertador
#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1, m1, h2, m2, ans;
    while(scanf("%d%d%d%d", &h1, &m1, &h2, &m2) && h1+m1+m2+h2 > 0){
        if(h1==h2){ //1 4 1 5 // 1 5 1 4
            if(m1 == m2) ans = 24*60;
            else if(m1 > m2) ans = 24*60 - (m1-m2);
            else if(m1 < m2) ans = m2-m1;
        }
        else{ //1 4 3 5 //1 5 3 4
            if(h1 > h2) h2+=24;
            if(m1 == m2) ans = (h2 - h1)*60;
            else if(m1 > m2) ans = (h2-h1-1)*60 + 60-(m1-m2);
            else if(m1 < m2) ans = (h2-h1)*60 + m2-m1;
        }
        printf("%d\n", ans);
    }

    return 0;
}