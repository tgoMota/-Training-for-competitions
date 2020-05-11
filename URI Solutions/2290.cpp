//https://www.urionlinejudge.com.br/judge/pt/problems/view/2290
//URI 2290 - Números Apaixornados
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(cin >> n && n){
        ll v[n];
        for(int i = 0; i < n ; ++i) scanf("%lld", v+i);
        sort(v, v+n);
        int cnt = 0;
        for(int i = 0; i < n ; ++i){
            if(v[i] == v[i+1] && i < n-1) i++;
            else{
                cout << v[i];
                if(cnt++ || n == 1) {
                    cout << endl;
                    break;
                }
                else cout << " ";
            }
        }
    }
    return 0;
}