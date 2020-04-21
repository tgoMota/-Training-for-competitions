//https://www.urionlinejudge.com.br/judge/pt/problems/view/2674
//URI 2674 - Super Primos: Ativar!
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    bool prime = true;
    for(int i = 2 ; i <= sqrt(n) ; ++i){
        if(n % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(!isPrime(n)) printf("Nada\n");
        else{
            bool fullPrime = true;
            while(n != 0){
                int k = n % 10;
                if(!isPrime(k)){
                    fullPrime = false;
                    break;
                }
                n/=10;
            }
            if(fullPrime) printf("Super\n");
            else printf("Primo\n");
        }
    }

    return 0;
}