#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string& pat){
    const int N = pat.size();
    int i = 0, j = -1;
    vector<int> lps(N+1);
    lps[0] = -1;
    while(i < N){
        while(j>=0 && pat[i] != pat[j]) j = lps[j];
        i++, j++;
        lps[i] = j;
    }
    return lps;
}

string kmp(string& data, string& pat){
    const int N = data.size(), M = pat.size();
    vector<int> lps = LPS(pat);
    int i = 0, j = 0, ans = 0;
    //abdcba ->data (reversed)
    //abcdba ->pat
    while(i < N){
        while(j>=0 && data[i] != pat[j]) j = lps[j];
        i++, j++;
        ans = max(ans, j);
    }
    return data.substr(N-ans,ans);
}

int main(){
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        string pat = s;
        reverse(pat.begin(), pat.end());
        cout << kmp(pat, s) << endl;
    }


    return 0;
}