#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, m;

int can(int x){
    int ans = 0;
    for(int i = 1; i < n ; ++i){
        int dif = v[i]-v[i-1];
        ans+= (dif+x-1)/x;
    }
    return ans;
}


int main(){
    scanf("%d%d", &n, &m);
    v.assign(n, 0);
    for(int& x : v) scanf("%d", &x);
    v.push_back(m+1);

    int lo = 1, hi = v.back(), mid;
    while(lo < hi){
        mid = (lo+hi)>>1;
        if(can(mid)<mid) hi = mid;
        else lo = mid+1;
    }

    printf("%d\n", lo);

    return 0;
}