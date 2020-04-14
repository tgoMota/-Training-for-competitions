#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", n%100 == 0 ? n/100 : n/100+1);
    }

    return 0;
}