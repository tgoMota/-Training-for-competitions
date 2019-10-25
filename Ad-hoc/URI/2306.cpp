//https://www.urionlinejudge.com.br/judge/en/problems/view/2306
//URI 2306 - Escada Perfeita
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0, a1, an, anj, ani;
    scanf("%d", &n);
    int stair[n];

    for(int i = 0; i < n ; ++i) {
        scanf("%d", &stair[i]);
        sum += stair[i]; // Sum = sn = ((a1+an)*n)/2      -> Sum of Arithmetic Progression
    }
    if(((n*n)*-1+n+2*sum) % (2*n) != 0){
        printf("-1\n");
        exit(0);
    }
    
    a1 = ((n*n)*-1+n+2*sum)/(2*n); //Manipulating the Arithmetic Progression for find the first term
    an = a1+n-1; // [a1..an] // last term of PA

    int swaps = 0, maxcanswap = 0;
    for(int i = 0; i < n ; ++i){
        ani = a1+i;// the term a(i) in PA
        if(stair[i] == ani) continue; //nothing to change in this step
        for(int j = 0; j < n ; ++j){
            maxcanswap = 0;
            anj = a1+j; // the term a(j) in PA
            if(i == j || stair[j] == anj) continue;
            if(stair[i] > ani && stair[j] < anj){
                maxcanswap = min(stair[i]-ani, anj - stair[j]);
                stair[i]-= maxcanswap;
                stair[j]+=maxcanswap;
            }
            if(stair[j] > anj && stair[i] < ani){
                maxcanswap = min(stair[j]-anj, ani - stair[i]);
                stair[j]-= maxcanswap;
                stair[i]+=maxcanswap;
            }
            swaps+=maxcanswap; // increasing the number of changes
        }
    }

    printf("%d\n", swaps);

    return 0;
}
