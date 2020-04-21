#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string& pat){
    const int N = pat.size();
    vector<int> lps(N+1);
    int i = 0, j = -1;
    lps[0] = -1;
    while(i < N){
        while(j >= 0 && pat[i] != pat[j]) j = lps[j];
        i++, j++;
        lps[i] = j;
    }
    return lps;
}

string kmp(string& data, string& pat){
    vector<int> lps = LPS(pat);
    const int N = data.size();
    const int M = pat.size();
    int i = 0, j = 0;
    while(i < N){
        while(j >= 0 && data[i] != pat[j]) j = lps[j];
        i++, j++;
    }
    return data + pat.substr(j, M-j);
}

int main(){
    string s;
    while(cin >> s){
        string pat = s;
        reverse(pat.begin(), pat.end());
        cout << kmp(s, pat) << endl;
    }

    return 0;
}