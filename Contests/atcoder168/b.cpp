#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    fastio();
    for(int ti = 1; ti <= 1 ; ++ti){
        int k;
        cin >> k;
        string s;
        cin >> s;
        const int N = s.size();
        string ans = s;
        if(N > k) ans = s.substr(0,k) + "...";
        
        cout << ans << endl;
    }
    return 0;
}