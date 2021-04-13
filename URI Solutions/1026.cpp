//https://www.urionlinejudge.com.br/judge/pt/problems/view/1026
//URI 1026 - Carrega ou não Carrega?
#include <bits/stdc++.h>
using namespace std;

int main(){

    unsigned int a , b, c;
    while(cin >> a >> b){
        c = 0;
        for(int i = 0; i < 32 ; ++i){
            if((a & 1<<i) && (b & 1<<i)) continue;
            else if((a & 1<<i) || (b & 1<<i)) c |= 1<<i;
        }
        if(c<0) c = INT_MAX*2+1;
        cout << c << endl;
    }

    return 0;
}
