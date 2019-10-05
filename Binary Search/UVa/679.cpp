//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=620
#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, d, I, n, ball;
    while(cin >> l){
        if(l == -1) break;
        while(l--){
            cin >> d >> I;
            ball = 1;
            for (int i = 0; i <= d - 2; i++){
                if (I % 2 == 1){
                    ball *= 2;
                    ++I/= 2;
                }else{
                    ball = ball * 2 + 1;
                    I /= 2;
                }
            }
                cout << ball << endl;
        }
    }

    return 0;
}
