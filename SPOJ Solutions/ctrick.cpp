//https://www.spoj.com/problems/CTRICK/
//SPOJ CTRICK - Card Trick
#include <bits/stdc++.h>
using namespace std;
vector<int> v, fen;
int n;
void add(int idx, int val){
    while(idx && idx <= n){
        fen[idx]+=val;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx && idx <= n){
        sum += fen[idx];
        idx-= idx & -idx;
    }
    return sum;
}

int query(int l, int r){
    return query(r) - query(l-1);
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        v.assign(n+1, 0);
        fen.assign(n+1, 0);
        for(int i = 1; i <= n ; ++i) add(i,1);

        int card = 1, last = 1;
        while(card <= n){
            int lo = last, hi = n, mid, d = 0;
            while(query(last, n) < card-d+1) d += query(last, n), lo = last = 1;
            while(lo < hi){
                int mid = lo + (hi-lo)/2;
                if(query(last,mid) >= card-d+1) hi = mid;
                else lo = mid+1;
            }
            add(lo, -1);
            last = lo;
            v[lo] = card++;
        }

        for(int i = 1; i <= n ; ++i) printf("%d ", v[i]);
        printf("\n");
    }

    return 0;
}