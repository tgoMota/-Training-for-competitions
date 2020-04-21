//https://www.urionlinejudge.com.br/judge/pt/problems/view/1089
//URI 1089 - Loop Musical
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n){
        vector<int> v(n);
        for(int& x : v) scanf("%d", &x);
        for(int i = 1; i < n ; ++i)
            if(v[i] == v[i-1]) v.erase(v.begin()+i);
        if(v[0] == v[n-1]) v.erase(v.begin());
        int ans = 0;
        if(v[0] > v[n-1] && v[0] > v[1] || v[0] < v[n-1] && v[0] < v[1]) ans++;
        if(v[n-1] > v[n-2] && v[n-1] > v[0] || v[n-1] < v[n-2] && v[n-1] < v[0]) ans++;

        for(int i = 1 ; i < n-1 ; ++i)
            if(v[i] > v[i-1] && v[i] > v[i+1] || (v[i] < v[i-1] && v[i] < v[i+1])) ans++;
        printf("%d\n", ans);
    }

    return 0;
}