//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=396
#include <bits/stdc++.h>
using namespace std;

int LPS(string& pat){
    const int N = pat.length();
    vector<int> lps(N+1);
    lps[0] = -1;
    int i = 0, j = -1, ans = 0;
    while(i < N){
        while(j>=0 && pat[i] != pat[j]) j = lps[j];
        i++, j++;
        lps[i] = j;
        ans = max(ans, j);
    }
    return N-ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        const int N = a.length(), ans = LPS(a);
        printf("%d\n", N%ans == 0 ? ans : N);
        if(t) printf("\n");
    }

    return 0;
}