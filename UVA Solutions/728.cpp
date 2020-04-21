//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=669
//USAR BIGINTEGER
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int memo[101], num[101], cont;

int pd(int i){
    if(i == cont) return 0;

}

int main(){
    int k;
    while(scanf("%d", &k)!=EOF){
        num[++cont] = k;
        if(k == -999999){
            memset(memo, -1, sizeof(memo));
            cout << pd() << endl;
            cont = 0;
        }
    }
    return 0;
}
