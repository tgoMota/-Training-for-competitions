//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2347
#include <bits/stdc++.h>
using namespace std;

bool match(string& data, string& pat){
    for(int i = 0, j = 0; i < data.size() && j < pat.size(); i++, j++){
        if(data[i] != pat[j]) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    string data;
    vector<string> v;

    for(int tc = 1; tc <= t; ++tc){
        int n;
        cin >> n;
        v.resize(n);

        for(string& x : v) cin >> x;
        sort(v.begin(), v.end());

        bool ok = false;
        for(int i = 1; i < v.size() ; ++i){
            ok =match(v[i], v[i-1]);
            if(ok) break;
        }

        printf("%s\n", ok? "NO" : "YES");
    }

    return 0;
}