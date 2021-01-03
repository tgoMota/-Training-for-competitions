#include <bits/stdc++.h>
using namespace std;
vector<int> v;
set<vector<int>> ans;

void back(int idx, int sum, vector<int> choosed, const int S, const int N){
    
    if(idx >= N || sum >= S){
        if(sum == S) {
            sort(choosed.begin(), choosed.end(), greater<int>());
            ans.insert(choosed);
        }
        return;
    }

    back(idx+1, sum, choosed, S, N);
    choosed.push_back(v[idx]);
    back(idx+1, sum+v[idx], choosed, S, N);
}

int main(){
    int S, N;
    while(scanf("%d%d", &S, &N) && S+N){
        v.resize(N);
        for(int& x : v) scanf("%d", &x);
        ans.clear();
        back(0,0,vector<int>(), S, N);
        printf("Sums of %d:\n", S);
        if(ans.empty()) {
            printf("NONE\n");
            continue;
        }
        vector<vector<int>> answer;
        for(auto& x : ans) answer.push_back(x);
        sort(answer.begin(), answer.end(), [&](vector<int>& a, vector<int>& b){
            const int szA = (int)a.size();
            const int szB = (int)b.size();
            for(int i = 0; i < szA && i < szB ; ++i){
                if(a[i] != b[i]) return a[i] > b[i];
            }
            return szA < szB;
        });
        for(auto& x : answer){
            for(int i = 0; i < (int)x.size() ; ++i){
                if(i) printf("+");
                printf("%d", x[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
