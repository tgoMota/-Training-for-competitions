#include <bits/stdc++.h>
using namespace std;

int LPS(string& pat){
    const int N = pat.size();
    vector<int> lps(N+1);
    int i = 0, j = -1;
    lps[0] = -1;

    while(i < N){
        while(j >= 0 && pat[i] != pat[j]) j = lps[j];
        i++, j++;
        lps[i] = j;
    }

    return N%(N-j) == 0 ? N/(N-j) : 1;
}

int main(){
    string a;
    while(cin >> a && a!="."){
        printf("%d\n", LPS(a));
    }

    return 0;
}