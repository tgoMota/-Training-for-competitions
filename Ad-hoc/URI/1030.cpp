//https://www.urionlinejudge.com.br/judge/pt/problems/view/1030
//URI 1030 - A Lenda de Flavious Josephus
#include <bits/stdc++.h>
using namespace std;
int clk, nc, n, s;
int main(){
    cin >> nc;
    while(nc--){
        cin >> n >> s;
        int ind = 0, cnt = 2;
        while(cnt<=n){
            ind = (ind+s)%cnt;
            cnt++;
        }
        cout << "Case " << ++clk << ": " << ++ind << endl;
    }

    return 0;
}