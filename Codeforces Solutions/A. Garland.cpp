//https://codeforces.com/contest/1286/problem/A
//A. Garland
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int n;

int memo[101][101][101][2];
vector<int> v;
int solve(int idx, int odd, int even, int last){
    if(odd < 0 || even < 0) return oo;
    if(idx == n) return odd == 0 && even == 0 ? 0 : oo;
    int& ans = memo[idx][odd][even][last];
    if(ans != -1) return ans;
    if(idx == 0){
        if(v[idx] == 0) return ans = min(solve(idx+1, odd-1, even, 1), solve(idx+1, odd, even-1, 0));
        else return ans = solve(idx+1, odd, even, v[idx]%2);
    }
    if(v[idx] != 0) return ans = ((v[idx]%2) != last) + solve(idx+1, odd, even, v[idx]%2);
    return ans = min((last == 0) + solve(idx+1, odd-1, even, 1), (last != 0) + solve(idx+1, odd, even-1, 0));
}


int main(){
    scanf("%d", &n);
    v.resize(n);
    vector<int> zeros;
    int minpos = n;
    int even = 0, odd = 0;
    for(int i = 0; i < n ; ++i){
        scanf("%d", &v[i]);
        if(v[i] == 0) continue;
        else if(v[i] % 2 == 0) even++;
        else odd++;
    }
    if(n % 2 == 0) even = n/2-even, odd = n/2-odd;
    else even = n/2-even, odd = n/2-odd+1;
    
    memset(memo, -1, sizeof(memo));
    printf("%d\n", solve(0,odd,even,0));
    return 0;
}