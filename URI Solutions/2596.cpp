//https://www.urionlinejudge.com.br/judge/pt/problems/view/2596
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e, memo[1001];
    cin >> n;
    memset(memo, -1, sizeof(memo)); //dynamic programming
    while(n--){
        cin >> e;
        int cont = 0, ans;
        for(int i = 2; i <= e ; ++i){
            ans = memo[i];
            if(ans != -1){ //previous calculated
                if(ans % 2 == 0) cont++;
                continue;
            }
            ans = 0;
            for(int j = 1 ; j <= i ; ++j)
                if(i % j == 0) ans++;
            memo[i] = ans;
            if(ans % 2 == 0) cont++;
        }
        cout << cont << endl;
    }

    return 0;
}
