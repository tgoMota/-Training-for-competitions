//https://www.urionlinejudge.com.br/judge/pt/problems/view/1039
//URI 1039 - Flores de Fogo
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

double dist(int x1, int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

  int main(){
    int x1,y1,r1, x2,y2,r2;
    while(scanf("%d%d%d%d%d%d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF){
      if(dist(x1,y1,x2,y2)+double(r2) <= double(r1)) printf("RICO\n");
      else printf("MORTO\n");
    }

  return 0;
}