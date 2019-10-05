//https://www.urionlinejudge.com.br/judge/pt/problems/view/2598
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, a, b;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &a, &b);
        printf("%d\n", a % b == 0 ? a/b : a/b + 1);
    }

    return 0;
}