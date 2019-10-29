//https://www.urionlinejudge.com.br/judge/pt/problems/view/2963
//URI 2963 - Bobo da Corte
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, mx = 0;
    cin >> n;
    int v[n];
    bool temD = false;
    for(int i = 0; i < n ; ++i) {
        scanf("%d", &v[i]);
        mx = max(v[i], mx);
        if(i != 0 && v[i-1]!=v[i]) temD = true;
    }
    if(!temD) printf("S\n");
    else if(temD && mx == v[0]) printf("S\n");
    else printf("N\n");


    return 0;
}