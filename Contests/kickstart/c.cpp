#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int t, n, k;

int sc(int x){
    int ans = 0;
    for(int i = 0; i+1 < n ; ++i){
        ans+= (v[i+1]-v[i]-1)/x;
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d%d", &n, &k);
        v.assign(n, 0);
        for(int& x : v) scanf("%d", &x);

        int lo = 1, hi = v.back()-v[0], mid, ans;
        while(lo <= hi){
            mid = (hi+lo)>>1;
            if(sc(mid) <= k) ans = mid,hi = mid-1;
            else lo = mid+1;
        }

        printf("Case #%d: %d\n", ti, ans);
    }

    return 0;
}