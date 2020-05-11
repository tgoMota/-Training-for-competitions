#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

int LPS(string& pat){
    const int N = pat.size();
    vector<int> lps(N+1);
    int i = 0, j = -1;
    lps[0] = -1;
    while(i < N){
        while(j>=0 && pat[i] != pat[j]) j = lps[j];
        i++, j++;
        lps[i] = j;
    }
    return j;
}

int main(){
    fastio();
    string s;
    while(cin >> s){
        const int N = s.size();
        int i = N % 2 == 0 ? 0 : 1;
        string str;
        int ans;
        while(i < N){
            str = s.substr(i, N-i);
            ans = LPS(str);
            if(ans == (int)str.size()/2) break;
            i += 2;
        }

        cout << s.substr(0,i+ans) << endl;
        
    }
    return 0;
}