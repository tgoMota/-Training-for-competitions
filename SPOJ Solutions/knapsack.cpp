//https://www.spoj.com/problems/KNAPSACK/
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int s, n, wgt[2020], price[2020], memo[2020][2020];
int pd(int cap, int i){
    if(cap < 0) return -oo;
    if(i == n || cap == 0) return 0;
    int& ans = memo[i][cap];
    if(ans != -1) return ans;
    return ans = max(pd(cap,i+1), pd(cap-wgt[i], i+1) + price[i]);
}

int main(){
    cin >> s >> n;
    memset(memo, -1, sizeof(memo)); 
    for(int i = 0 ; i < n ; ++i) cin >> wgt[i] >> price[i];
    cout << pd(s,0) << endl;
    return 0;
}