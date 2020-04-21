#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    while(n-- && cin >> a >> b){
        if(a < b) printf("<");
        else if(a > b) printf(">");
        else printf("=");
        printf("\n");
    }
    return 0;
}