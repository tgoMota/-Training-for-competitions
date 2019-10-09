//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3249
//12097 - Pie || UVa
#include <bits/stdc++.h>
using namespace std;
const int m = 1e4+5;
int n, f, t;
double pie[m], vol[m];

bool can(double mid){
    int pieces = 0;
    for(int i = 1; i <= n ; ++i) pieces += (int)(vol[i]/mid);
    return (pieces >= f);
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> f;
        for(int i = 1; i <= n ; ++i){
            cin >> pie[i];
            vol[i] = pie[i]*pie[i]*M_PI;
        }
        double hi = m*m*M_PI, lo = 0.0, mid;
        ++f;
        for(int i = 0; i < 60 ; ++i){
            mid = (lo+hi)/2.0;
            if(can(mid)) lo = mid;
            else hi = mid;
        }
        printf("%.4lf\n", lo);
    }

    return 0;
}