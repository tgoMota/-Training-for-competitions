//https://www.urionlinejudge.com.br/judge/pt/problems/view/1029
//URI 1029 - Fibonacci, Quantas Chamadas?
#include <bits/stdc++.h>
using namespace std;

int fib(int n, int& x){
    if(n <= 1) return n;
    x = x+2;
    return fib(n-1, x)+fib(n-2, x);
}

int main(){
    
    int calls, n, ans, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = fib(n, calls = 0);
        printf("fib(%d) = %d calls = %d\n",n, calls, ans);
    }
    
    return 0;
}