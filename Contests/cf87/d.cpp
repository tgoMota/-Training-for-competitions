#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
const int N = 1e6+5;
int fen[N];
void update(int idx, int val, const int n){
    while(idx > 0 && idx <= n){
        fen[idx]+=val;
        idx += (idx & -idx);
    }
}

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += fen[idx];
        idx -= (idx & -idx);
    }
    return sum;
}


int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n ; ++i){
        int a;
        scanf("%d", &a);
        update(a, 1, n);
    }

    for(int i = 0; i < q ; ++i){
        int x;
        scanf("%d", &x);
        if(x > 0) update(x, 1, n);
        else{
            x = -x;
            int lo = 1, hi = n;
            while(lo < hi){
                int mid = lo + (hi-lo)/2;
                if(query(mid) >= x) hi = mid;
                else lo = mid+1;
            }
            update(lo, -1, n);
        }
    }

    if(query(n) <= 0) printf("0\n");
    else {
        int lo = 1, hi = n;
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(query(mid) >= 1) hi = mid;
            else lo = mid+1;
        }

        printf("%d\n", lo);
    }

    return 0;
}