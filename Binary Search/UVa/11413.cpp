//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2408
#include <bits/stdc++.h>
using namespace std;
int n, m, belt[1005];
bool can(int maxCap){
    int con = 1, bel = 0;
    for(int i = 1; i <= n ; ++i){
        int milks = belt[i]-belt[bel];
        if(con > m || milks > maxCap) return false;
        if(bel < n && belt[i+1]-belt[bel] > maxCap){
            bel = i;
            con++;
        }
    }
    return true;
}

int main(){
    while(cin >> n >> m && !cin.eof()){
        for(int i = 1; i <= n ; ++i){
            cin >> belt[i];
            belt[i] += belt[i-1];
        }

        int hi = 1e9+10, lo = 0, mid;
        while(lo < hi){
            mid = (hi+lo) >> 1;
            if(can(mid)) hi = mid;
            else lo = mid+1;
        }

        cout << lo << endl;
    }
}