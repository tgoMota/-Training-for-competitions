////https://www.urionlinejudge.com.br/judge/pt/problems/view/1061
//URI 1061 - Tempo de um Evento
#include <bits/stdc++.h>
using namespace std;

int main(){

    string day;
    char t[50];
    int d1 = 0, d2 = 0, h1 = 0, m1 = 0, s1 = 0, h2 = 0, m2 = 0, s2 = 0, d3 = 0,h3 = 0 ,m3 = 0, s3 = 0, sum1 = 0, sum2 = 0, ans = 0;
    getline(cin, day);
    sscanf(day.c_str(),"%s %4d", &t, &d1);
    getline(cin, day);
    sscanf(day.c_str(), "%2d : %2d : %2d", &h1, &m1, &s1);
    getline(cin, day);
    sscanf(day.c_str(),"%s %4d", &t, &d2);
    getline(cin, day);
    sscanf(day.c_str(), "%2d : %2d : %2d", &h2, &m2, &s2);
    //Dia 9
    //08 : 12 : 23
    //Dia 9
    //08 : 13 : 23
    sum1 = d1*86400 + h1*3600 + m1*60 + s1;
    sum2 = d2*86400 + h2*3600 + m2*60 + s2;
    ans = sum2-sum1;
    if(ans >= 86400) {
        d3 = ans/86400;
        ans -= (d3*86400);
    }
    if(ans >= 3600){
        h3 = ans/3600;
        ans -= (h3*3600);
    }
    if(ans >= 60) {
        m3 = ans/60;
        ans -= (m3*60);
    }
    s3 = ans;
    printf("%d dia(s)\n", d3);
    printf("%d hora(s)\n", h3);
    printf("%d minuto(s)\n", m3);
    printf("%d segundo(s)\n", s3);
    return 0;
}