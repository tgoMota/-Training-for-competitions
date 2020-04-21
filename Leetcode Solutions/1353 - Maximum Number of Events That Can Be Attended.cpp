//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
//1353. Maximum Number of Events That Can Be Attended
const int N = 1e5+2, oo = 0x3f3f3f3f;
class Solution {
public:
    int t[4*N];
    void build(int i, int l, int r){
        if(l == r) t[i] = l;
        else{
            int m = (l+r)>>1;
            build(2*i, l, m);
            build(2*i+1, m+1, r);
            t[i] = min(t[2*i], t[2*i+1]);
        }
    }
    
    int query(int i, int l, int r, int ql, int qr){
        if(ql <= l && qr >= r) return t[i];
        if(ql > r || qr < l) return oo;
        int m = (l+r)>>1;
        return min(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
    }
    
    void update(int i, int l, int r, int p, int x){
        if(l == r) t[i] = x;
        else{
            int m = (l+r)>>1;
            if(p <= m) update(2*i, l, m, p, x);
            else update(2*i+1, m+1, r, p, x);
            t[i] = min(t[2*i], t[2*i+1]);
        }
    }
    
    
    int maxEvents(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        build(1, 1, N);
        int r, ans = 0;
        for(int i = 0; i < e.size() ; ++i){
            r = query(1, 1, N, e[i][0], e[i][1]);
            if(r>= e[i][0] && r <= e[i][1]){
                ans++;
                update(1, 1, N, r, oo);
            }
        }
        return ans;
    }
};