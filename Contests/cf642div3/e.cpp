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
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ones = count(s.begin(), s.end(), '1');
        int ans = ones;
        for(int i = 0; i < k ; ++i){
            for(int j = i, dif = 0; j < n ; j+=k){
                dif += (s[j] == '1') ? 1 : -1;
                dif = max(dif, 0);
                ans = min(ans, ones-dif);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}