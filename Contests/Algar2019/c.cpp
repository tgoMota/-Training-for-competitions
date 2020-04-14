#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, good = 1;
    map<string,int> m;
    string a;
    scanf("%d", &n);
    for(int i = 0; i < n ; ++i){
        cin >> a;
        if(m[a] > 0) good = 0;
        else m[a]++;
    }

    if(good) printf("A funcao eh boa.\n");
    else printf("A funcao nao eh boa.\n");

    return 0;
}