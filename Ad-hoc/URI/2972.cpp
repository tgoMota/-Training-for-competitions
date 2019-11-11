//https://www.urionlinejudge.com.br/judge/pt/problems/view/2972
//URI 2972 - Lançando Moedas
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", 1LL << (__builtin_popcountll(n)));

    return 0;
}