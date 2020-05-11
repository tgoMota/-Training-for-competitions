#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    string s;
    cin >> s;
    const int N = s.size();
    ll ans = 0LL;
    int rest = 0, pot = 1;
    vector<int> memo(2019);
    memo[0] = 1;
    for(int i = N-1; i >= 0 ; --i){
        int digit = s[i]-'0';
        rest = (rest + digit*pot)%2019;
        ans += memo[rest];
        memo[rest]++;
        pot = (pot*10)%2019;
    }

    cout << ans << endl;
    return 0;
}