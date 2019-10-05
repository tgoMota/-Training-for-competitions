//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=448
#include <bits/stdc++.h>
using namespace std;

int b, rt[20001], s;
map<int,int> res;

int main(){
    cin >> b;
    int k = b;
    while(k--){
        cin >> s;
        for(int i = 1; i < s ; ++i) cin >> rt[i];
        int ans = 0, sum = 0, ini = 0, fim = 0;
        for(int i = 1; i < s ; ++i){
            sum+=rt[i];
            if(max(ans,sum) == sum && ans != sum) {
                fim = i;
                res.insert(pair<int,int>(sum, ini));
            }
            if(sum == ans){
                if(i - ini > fim - res.find(ans)->second){
                    res.erase(res.find(ans));
                    res.insert(pair<int,int>(sum, ini));
                    fim = i;
                }
            }
            ans = max(ans, sum);
            if(sum < 0) {
                sum = 0;
                ini = i;
            } 
        }
        ini = res.find(ans)->second;
        if(!ans) printf("Route %d has no nice parts\n", b-k);
        else printf("The nicest part of route %d is between stops %d and %d\n", b-k, ini+1, fim+1);
        res.clear();
    }

    return 0;
}
