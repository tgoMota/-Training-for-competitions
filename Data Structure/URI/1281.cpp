#include <bits/stdc++.h>
using namespace std;
int n, d, q, k;
double p, ans, qtd;
string t;
int main(){
    map<string, double> lp;
    cin >> n;
    while(n--){
        cin >> d;
        while(d--){
            cin >> t >> p;
            lp[t] = p;
        }
        cin >> k;
        ans = 0.0;
        while(k--){
            cin >> t >> qtd;
            ans += lp[t]*qtd;
        }
        printf("R$ %.2lf\n", ans);
        lp.clear();
    }

    return 0;
}
