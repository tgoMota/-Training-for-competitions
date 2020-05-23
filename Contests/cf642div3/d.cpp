#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
vector<int> v;

struct interval{
    int l, r;
    interval(int L, int R) : l(L), r(R) {};
    bool operator<(const interval& a) const {
        if(r-l == a.r-a.l) return l < a.l;
        return r-l > a.r-a.l;
    }
};

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        v.assign(n, 0);
        set<interval> pq;
        int time = 0, mid;
        pq.insert(interval(0,n-1));

        while(!pq.empty()){
            auto x = *pq.begin();
            pq.erase(pq.begin());
            int l = x.l;
            int r = x.r;
            if(l > r) continue;
            mid = (l+r)>>1;
            v[mid] = ++time;
            pq.insert(interval(l, mid-1));
            pq.insert(interval(mid+1, r));

        }

        for(int i = 0; i < n ; ++i){
            if(i == 0) printf("%d", v[i]);
            else printf(" %d", v[i]);
        }
        printf("\n");
    }

    return 0;
}