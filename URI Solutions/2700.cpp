// https://www.urionlinejudge.com.br/judge/pt/problems/view/2700
// URI 2700 - Angariando Fundos
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef long long ll;

bool cmp(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
    if(a.second.first < b.second.first && a.second.second < b.second.second) return true;
}
int main(){
    int N;
    scanf("%d", &N);
    vector<pair<int,pair<int,int>>> v;
    for(int i = 0; i < N ; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v.push_back({c,{a,b}});

    }
    sort(v.begin(), v.end(), cmp);
    
    for(auto x : v) printf("{%d,%d,%d} ", x.first, x.second.first, x.second.second);
    printf("\n");
    unordered_map<int,bool> vst;
    ll maxsum = 0LL, sum = 0LL;
    for(int i = 0; i < N ; ++i){
        sum = 0LL;
        if(vst.find(i) != vst.end()) continue;
        //printf("i = %d\n", i);
        for(int j = i; j < N ; ++j){
            if((v[i].second.first < v[j].second.first && v[i].second.second < v[j].second.second) || (v[i].second.first == v[j].second.first && v[i].second.second == v[j].second.second)){
                sum+=v[j].first;
                vst[j] = true;
            }
            maxsum = max(maxsum, sum);
        }
        //printf("\n");
    }

    printf("%lld\n", maxsum);

    return 0;
}