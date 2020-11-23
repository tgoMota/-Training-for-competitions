//https://www.urionlinejudge.com.br/judge/pt/problems/view/1124
//URI 1124 - Elevador
#include <bits/stdc++.h>
using namespace std;

int main(){
  int l, c, r1, r2;
  while(scanf("%d%d%d%d", &l, &c, &r1, &r2) && l+c+r1+r2){
    if(r1 < r2) swap(r1,r2);
    if(l < c) swap(l,c);
    int distC = r1+r2, A = l-distC, B = c-distC, H = A*A + B*B;
    if(H >= distC*distC && c >= 2*r1) printf("S\n");
    else  printf("N\n");
  }

  return 0;
}