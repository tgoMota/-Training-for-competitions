#include <bits/stdc++.h>
using namespace std;
#define ooLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int M = 100;
ll grid[M][M];

ll cost(int x, int y, int i, int j){
    ll c = grid[i][j] + (x+y) - (i+j);
    if(c > grid[x][y]) return ooLL;
    return grid[x][y]-c;
}

int main(){
    ios_base::sync_with_stdio(0);
    std::fixed;
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n ; ++i) for(int j = 0; j < m ; ++j) cin >> grid[i][j];

        ll ans = ooLL;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                vector<vector<ll>> dp(n, vector<ll>(m, ooLL));
                dp[0][0] = 0;
                for(int x = 0; x < n ; ++x){
                    for(int y = 0; y < m ; ++y){
                        if(x) dp[x][y] = min(dp[x][y], dp[x-1][y]);
                        if(y) dp[x][y] = min(dp[x][y], dp[x][y-1]);
                        dp[x][y] += cost(x,y,i,j);
                        dp[x][y] = min(dp[x][y], (ll)ooLL);
                    }
                }
                ans = min(ans, dp[n-1][m-1]);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}













// #include <bits/stdc++.h>
// using namespace std;
 
// #define ll long long
// #define ar array
 
// const int mxN=100;
// int n, m;
// ll a[mxN][mxN], dp[mxN][mxN];
 
// ll ev(int x, int y, int i, int j) {
// 	ll nh=a[x][y]+(i+j)-(x+y);
// 	if(nh>a[i][j])
// 		return 1e18;
// 	return a[i][j]-nh;
// }
 
// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
 
// 	int t;
// 	cin >> t;
// 	while(t--) {
// 		cin >> n >> m;
// 		for(int i=0; i<n; ++i)
// 			for(int j=0; j<m; ++j)
// 				cin >> a[i][j];
// 		ll ans=1e18;
// 		for(int x=0; x<n; ++x) {
// 			for(int y=0; y<m; ++y) {
// 				for(int i=0; i<n; ++i) {
// 					for(int j=0; j<m; ++j) {
// 						if(i||j)
// 							dp[i][j]=1e18;
// 						else
// 							dp[i][j]=0;
// 						if(i)
// 							dp[i][j]=min(dp[i-1][j], dp[i][j]);
// 						if(j)
// 							dp[i][j]=min(dp[i][j-1], dp[i][j]);
// 						dp[i][j]+=ev(x, y, i, j);
// 						dp[i][j]=min(dp[i][j], (ll)1e18);
// 					}
// 				}
// 				ans=min(dp[n-1][m-1], ans);
// 			}
// 		}
// 		cout << ans << "\n";
// 	}
// }