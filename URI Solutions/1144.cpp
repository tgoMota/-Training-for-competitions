//https://www.urionlinejudge.com.br/judge/pt/problems/view/1144
//URI 1144 - Sequência Lógica
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i =1 ; i <= n ; ++i){
        printf("%d %d %d\n", i, i*i, i*i*i);
        printf("%d %d %d\n", i, i*i+1, i*i*i+1);
    }
    return 0;
}