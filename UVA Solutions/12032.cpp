//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183
//12032 - The Monkey and the Oiled Bamboo || UVa
#include <bits/stdc++.h>
using namespace std;
const int m = 1e5+5;
int rungs[m], t, n, clk;

bool can(int mid){
    for(int i = 1; i <= n ; ++i){
        if(mid < rungs[i] - rungs[i-1]) return false;
        if(mid == rungs[i]-rungs[i-1]) mid--;
    }
    return true;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n ; ++i) cin >> rungs[i];
        int lo = 0, hi = 1e7+10, mid;
        while(lo < hi){
            mid = (lo+hi)>>1;
            if(can(mid)) hi = mid;
            else lo = mid+1;
        }
        cout << "Case " << ++clk << ": " << lo << endl;
    }

    return 0;
}