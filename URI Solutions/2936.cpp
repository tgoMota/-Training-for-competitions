//https://www.urionlinejudge.com.br/judge/pt/problems/view/2936
//Quanta Mandioca?
#include <bits/stdc++.h>
using namespace std;

int main(){
    int v[] = {300, 1500, 600, 1000, 150}, sum = 225, k;
    for(int i = 0; i < 5 ; ++i){
        scanf("%d", &k);
        sum+=v[i]*k;
    }
    printf("%d\n", sum);
    return 0;
}