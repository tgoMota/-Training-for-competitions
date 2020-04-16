//https://codeforces.com/problemset/problem/189/A
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int comp[4], memo[4010];

int pd(int t){
    if(t == 0) return 0;
    if(t < 0) return -oo;
    int& ans = memo[t];
    if(ans != -1) return ans;  
    ans = -oo; 
    for(int i = 1; i <= 3 ; ++i)
        ans = max(ans, pd(t-comp[i]) + 1);
    return ans;
}

//Other way to solve...
// int pd(int t){
//     if(t == 0) return 0;
//     if(t < 0) return -oo;
//     int& ans = memo[t];
//     if(ans != -1) return ans;
//     return ans = 1 + max(max(pd(t-comp[1]), pd(t-comp[2])), pd(t-comp[3]));
// }

int main(){

    cin >> comp[0] >> comp[1] >> comp[2] >> comp[3];
    memset(memo, -1, sizeof(memo));
    cout << pd(comp[0])<< endl;
    return 0;
}