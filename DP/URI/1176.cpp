//https://www.urionlinejudge.com.br/judge/pt/problems/view/1176
#include <bits/stdc++.h>
using namespace std;

unsigned long long int memo[62], t;
unsigned long long int fibo(int n){
    unsigned long long int& ans = memo[n];
    if(ans != -1) return ans;
    return ans = fibo(n-1) + fibo(n-2);
}

int main(){

    int n, l;
    cin >> n;
    while(n--){
        memset(memo, -1, sizeof(memo));
        memo[0] = 0;
        memo[1] = 1;
        cin >> l;
        printf("Fib(%d) = %llu\n", l, fibo(l));
    }

    return 0;
}