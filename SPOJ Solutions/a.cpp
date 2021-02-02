//https://www.spoj.com/problems/MKTHNUM/
//MKTHNUM - K-th Number
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<int> v, v2;

struct Seg{
    vector<vector<int>> t;
    Seg(const int n){
        t.assign(4*n, vector<int>());
    }

    void build(int i, int l, int r){
        if(l == r){
            t[i].push_back(v2[l]);
            return;
        }
        int m = (l+r)>>1;
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        merge(t[2*i].begin(),t[2*i].end(),t[2*i+1].begin(), t[2*i+1].end(), back_inserter(t[i]));
    }

    int query(int i, int l, int r, int ql, int qr, int k){
        if(ql > r || qr < l || l > r) return 0;
        if(ql <= l && qr >= r){
            return upper_bound(t[i].begin(),t[i].end(),k) - t[i].begin();
        }
        int m = (l+r)>>1;
        return query(2*i, l, m, ql, qr, k) + query(2*i+1, m+1, r, ql, qr, k);
    }
};

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    v.resize(n+1);
    v2.resize(n+1);
    for(int i = 1; i <= n ; ++i){
        scanf("%d", &v[i]);
        v2[i] = v[i];
    }
    v[0] = -INT_MAX;
    sort(v.begin(), v.end());
    Seg seg(n);
    for(int i = 1; i <= n ; ++i){
        v2[i] = lower_bound(v.begin(), v.end(), v2[i])-v.begin();
    }
    seg.build(1, 1, n);
   while(q--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int lo = 1, hi = n, mid, ans;
    while(lo <= hi){
        mid = (lo+hi)>>1;
        int x = seg.query(1,1,n,a,b,mid);
        if(x >= c) hi = mid-1, ans = mid;
        else lo = mid+1;
    }
    printf("%d\n", v[ans]);
   }
   
    return 0;
}