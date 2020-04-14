#include <bits/stdc++.h>

using namespace std;

const int N = 112345;
const int oo = 0x3f3f3f3f;
vector<int> st[4*N];
void clear(){
    for(int i = 0; i < 4*N ; ++i) st[i].clear();
}
int a[N];
void merge(int n, int left, int right) {
    int lptr = 0, rptr = 0, cptr = 0;;
    while (lptr < st[left].size() || rptr < st[right].size()) {
        if (lptr == st[left].size())
            st[n][cptr++] = st[right][rptr++];
        else if (rptr == st[right].size())
            st[n][cptr++] = st[left][lptr++];
        else {
            if (st[left][lptr] < st[right][rptr])
                st[n][cptr++] = st[left][lptr++];
            else
                st[n][cptr++] = st[right][rptr++];
        }
    }
}

void construct(int n, int ll, int rl) {
    if (ll == rl) {
        st[n].push_back(a[ll]);
        return;
    }
    construct(2*n+1, ll, (ll+rl)/2);
    construct(2*n+2, (ll+rl)/2+1, rl);
    st[n].resize(rl-ll+1);
    merge(n, 2*n+1, 2*n+2);
}

int query(int n, int ll, int rl, int ql, int qr, int k) {
    if (rl < ql || ll > qr) return 0;
    if (ll >= ql && rl <= qr) {
        int t = st[n].end()-upper_bound(st[n].begin(), st[n].end(), k);
        return t;
    }
    int left = query(2*n+1, ll, (ll+rl)/2, ql, qr, k);
    int right = query(2*n+2, (ll+rl)/2+1, rl, ql, qr, k);
    return left + right;
}


int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n ; ++i){
        scanf("%d", &a[i]);
    }
    construct(0, 0, n-1);
    for(int i = 0; i < q ;){
        int id, p , l, r, x;
        bool updated = false;
        while(i < q && scanf("%d", &id) && id == 1){
            updated = true;
            scanf("%d%d", &p, &x);
            a[p-1] = x;
            i++;
        }
        if(i == q) break;
        if(updated){
            clear();
            construct(0, 0, n-1);
        }
        updated = false;
        if(id == 2){ //query
            scanf("%d%d%d", &x, &l, &r);
            l--, r--;
            printf("%d\n", query(0, 0, n-1, l, r, x));
            i++;
        }
    }
    return 0;
}