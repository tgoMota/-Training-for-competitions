//https://www.urionlinejudge.com.br/judge/pt/problems/view/2232
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &k);
        printf("%d\n", (int)(pow(2,k)) - 1);
    }

    return 0;
}