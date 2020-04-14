#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n >= 0){
        int a = 1;
        int b = n % 257;
        int c = n % 193;

        if(b == 0 && c == 0 || (c == 0)) printf("Bom\n");
        else printf("So o ouro\n");
    }
    return 0;
}