//https://www.urionlinejudge.com.br/judge/pt/problems/view/2313
//URI 2313 - Qual Triângulo
#include <bits/stdc++.h>
using namespace std;
bool isValid(int a, int b, int c){
    if(a+b <= c) return false;
    if(a+c <= b) return false;
    if(b+c <= a) return false;
    return true;
}
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(!isValid(a,b,c)) printf("Invalido\n");
    else{
        if(a == b && b == c) printf("Valido-Equilatero\n");
        else if(a == b || a == c || b == c) printf("Valido-Isoceles\n");
        else printf("Valido-Escaleno\n");
        printf("Retangulo: ");
        if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) printf("S\n");
        else printf("N\n");
    }
    return 0;
}