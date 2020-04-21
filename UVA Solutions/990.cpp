#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int t, w, n, dep[31], gold[31], memo[31][1001];
vector<int> res;

int pd(int resta, int ind){
    if(resta < 0) return -oo;
    if(ind == 0 || resta == 0) return 0;
    int& ans = memo[ind][resta];
    if(ans != -1) return ans;
    int time = w*dep[ind] + 2*w*dep[ind]; 
    return ans = max(pd(resta,ind-1), pd(resta-time, ind-1) + gold[ind]);
}

void recover(int resta, int ind){
    if(ind == 0) return;
    int time = w*dep[ind] + 2*w*dep[ind]; 
    int pega = pd(resta-time, ind-1) + gold[ind];
    int passa = pd(resta,ind-1);
    if(pega >= passa){
        res.push_back(ind);
        recover(resta-time, ind-1);
    }else{
        recover(resta, ind-1);
    }
}
int main(){
    while(scanf("%d%d", &t, &w) != EOF){
        scanf("%d", &n);
        for(int i = 1; i <= n ; ++i) cin >> dep[i] >> gold[i];
        memset(memo, -1, sizeof(memo));
        int ans = pd(t, n);
        recover(t,n);
        printf("%d\n%d\n", ans, res.size());
        for(int i = res.size()-1; i >= 0 ; --i) printf("%d %d\n", dep[res[i]], gold[res[i]]);
        printf("\n");
    }

    return 0;
}