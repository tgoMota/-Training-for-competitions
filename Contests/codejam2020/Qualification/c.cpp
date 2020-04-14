#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
const int M = 24*60+5;

class Seg{
    public:
    int t[4*M], lz[4*M];

    Seg(){}

    void push(int i, int l, int r) {
        if (lz[i]) {
            t[i] += lz[i] * (r-l+1);
            if (l != r) {
                lz[2*i] += lz[i];
                lz[2*i+1] += lz[i];
            }
            lz[i] = 0;
        }
    }

    int query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (ql <= l && r <= qr) return t[i];
        if (qr < l || r < ql) return 0;
        int m = (l+r)/2;
        return query(2*i, l, m, ql, qr)
            + query(2*i+1, m+1, r, ql, qr);
    }

    void update(int i, int l, int r, int ql, int qr, int x) {
        push(i, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lz[i] += x;
            push(i, l, r);
        } else {
            int m = (l+r)/2;
            update(2*i, l, m, ql, qr, x);
            update(2*i+1, m+1, r, ql, qr, x);
            
            t[i] = t[2*i] + t[2*i+1];
        }
    }
};
typedef long long ll;

int main(){
    int t, n;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        vector<pair<pair<int,int>, int>> v;
        //360 480
        //420 540
        //600 660
        cin >> n;
        for(int i = 0; i < n ; ++i){
            int a, b;
            cin >> a >> b;
            v.push_back({{a,b}, i});
        }
        sort(v.begin(), v.end(), [&](pair<pair<int,int>, int>& a, pair<pair<int,int>, int>& b){
            return a.first.first < b.first.first;
        });

        Seg *c = new Seg();
        Seg *j = new Seg();
        string ans(n, 'a');
        for(int i = 0; i < v.size() ; ++i){
            int ql = v[i].first.first, qr = v[i].first.second;
            int cq = c->query(1, 0, M, ql, qr);
            int pos = v[i].second;
            int jq;
            if(cq < M){
                ans[pos] = 'C';
                c->update(1, 0, M, ql, qr-1, M);
            }
            else{
                jq = j->query(1, 0, M, ql, qr);
                if(jq < M){
                    ans[pos] = 'J';
                    j->update(1, 0, M, ql, qr-1, M);
                }else{
                    ans = "IMPOSSIBLE";
                    break;
                }
            }
        }
        printf("Case #%d: %s\n", ti, ans.c_str());
    }

    return 0;
}