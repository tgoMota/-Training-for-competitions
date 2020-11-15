#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int memo[10005];

int fat(int n){
    if(n == 0 || n == 1) return 1;
    int& ans = memo[n];
    if(ans != -1) return ans;
    return ans = n*fat(n-1);
}

int main(){
        int n;
        while(scanf("%d", &n) && n){
            memset(memo, -1, sizeof(memo));
            printf("%d\n", fat(n));
        }
    return 0;
}