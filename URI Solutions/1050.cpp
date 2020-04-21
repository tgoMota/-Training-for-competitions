//https://www.urionlinejudge.com.br/judge/pt/problems/view/1050
//URI 1050 - DDD
#include <bits/stdc++.h>
using namespace std;

int main(){
    int ddd;
    string ans;
    cin >> ddd;
    if(ddd == 61) ans = "Brasilia";
    else if(ddd == 71) ans = "Salvador";
    else if(ddd == 11) ans = "Sao Paulo";
    else if(ddd == 21) ans = "Rio de Janeiro";
    else if(ddd == 32) ans = "Juiz de Fora";
    else if(ddd == 19) ans = "Campinas";
    else if(ddd == 27) ans = "Vitoria";
    else if(ddd == 31) ans = "Belo Horizonte";
    else ans = "DDD nao cadastrado";
    cout << ans << endl;

    return 0;
}