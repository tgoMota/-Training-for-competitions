//https://www.urionlinejudge.com.br/judge/pt/problems/view/2881
//URI 2881 - Festival
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int n, memo[1030][1005], sz;
struct show{
    int ij,fi,oj,palco;
};
vector<show> sh;
vector<int> nextS;

bool cmp(const show &sw1, const show &sw2){
    return sw1.ij < sw2.ij;
}

int pd(int mask, int ind){
    if(ind == sz) return mask == (1<<n)-1? 0 : -oo;
    int& ans = memo[mask][ind];
    if(ans != -1) return ans;
    return ans = max(pd(mask,ind+1), pd(mask| 1 << sh[ind].palco, nextS[ind]) + sh[ind].oj);
}

int main(){
    cin >> n;
    int ij, fi, oj, nshows;
    for(int i = 1; i <= n ; ++i){
        cin >> nshows;
        for(int j = 1; j <= nshows ; ++j) {
            cin >> ij >> fi >> oj;
            show SH;
            SH.ij = ij;
            SH.fi = fi;
            SH.oj = oj;
            SH.palco = i-1;
            sh.push_back(SH);
        }
    }
    sort(sh.begin(), sh.end(), cmp);
    sz = sh.size();
    memset(memo, -1, sizeof(memo));
    nextS.assign(sz, sz);
    for(int i = 0; i < sz ; ++i){
        for(int j = i+1; j < sz ; ++j){
            if(sh[i].fi <= sh[j].ij){
                nextS[i] = j;
                break;
            }
        }
    }
    int ans = pd(0,0);
    printf("%d\n", ans <= 0 ? -1 : ans);
    return 0;
}
