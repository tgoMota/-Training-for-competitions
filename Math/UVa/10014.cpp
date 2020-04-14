#include <bits/stdc++.h>
using namespace std;
vector<double> c;
int main(){
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        double a0, an1;
        cin >> a0 >> an1;
        c.resize(n);
        for(int i = 0; i < n ; ++i) cin >> c[i];

        printf("%.2lf\n", dp[1]/2.0);
    }
    return 0;
}