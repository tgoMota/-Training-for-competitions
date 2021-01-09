#include <bits/stdc++.h>
using namespace std;
double memo[1005][1005][2];

double solve(int idx, int turn, const int n){

}

int main(){
    int n;
    scanf("%d", &n);
    vector<double> v(2*n);
    double sum = 0;
    for(double& x : v) {
        scanf("%lf", &x);
        sum += x;
    }
    memset(memo, -1, sizeof(memo));
    return 0;
}