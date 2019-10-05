#include <bits/stdc++.h>
using namespace std;

unsigned long long int fibo(int n){
    unsigned long long int v[n];
    int i;
    v[0] = 0;
    v[1] = 1;
    for(i = 2; i <= n ; ++i){
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];
}

unsigned long long int binToDec(char a[]){
    int i, k = strlen(a)-1;
    unsigned long long int dec = 0;
    //printf("%s\n", a);
    for(i = k; i >= 0 ; --i){
        if(a[i] == '1'){
           // printf("i = %d\n", i);
            dec += pow(2, k - i);
        }
    }
    return dec;
}

int main(){

    int n,k,i, s[3];
    char bin[10001];
    unsigned long long int r;
    scanf("%d", &n);
    while(n-->0 && scanf("%s", bin)){
        r = binToDec(bin);
        //printf("\n%bin to dec = %lli\n", r);
        r = fibo(r);
        printf("r = %lli\n", r);
        //printf("\nr = %lli\n", r);
        for(i = 2; i >= 0 ; --i){
            s[i] = 0;
            if(r != 0){
                s[i] = r % 10;
                r /= 10;
            }
        }

        printf("%d%d%d\n", s[0], s[1], s[2]);
    }

return 0;
}
