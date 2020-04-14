#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string& pat){
    const int N = pat.length();
    vector<int> lps(N+1);
    lps[0] = -1;
    int i = 1, j = -1;
    while(i < N){
        while(j>=0 && pat[i] != pat[j+1]) j = lps[j];
        if(pat[i] == pat[j]) j++;
        lps[i] = j;
        i++;
    }
    return lps;
}

int kmp(string& data, string& pat){
    vector<int> lps = LPS(pat);
    const int N = data.length();
    const int M = pat.length();
    int i = 0, j = -1, ans = -1;
    while(i < N && i + M - j + 1 <= N){
        while(j>= 0 && data[i] != pat[j+1]) j = lps[j];
        if(data[i] == pat[j+1]) j++;
        i++;
        if(j == M-1){
            int dif = i-M+1;
            if(dif>0) return dif;
            ans = 0;
            j = lps[j];
        }
    }
    return ans;
}
//aabaaa$aabaaa
//aaabaa


int main(){
    int t;
    cin >> t;
    string data, cpy;
    while(t--){
        cin >> data;
        const int N = data.length();
        cpy = data;
        reverse(cpy.begin(), cpy.end());
        data+=data;
        int ans = kmp(data, cpy);
        if(ans == 0 || ans == N) printf("palindrome");
        else if(ans == -1) printf("simple\n");
        else printf("alindrome\n");
    }

    return 0;
}