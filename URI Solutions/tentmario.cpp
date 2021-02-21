#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
int A, B, M, L, K;
vector<vector<ii>> adj;
void min_self(int& a, int b){
  a = min(a, b);
}
int main(){
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> A >> B >> M >> L >> K;
        const int N = A+B;
        adj.assign(N+1, vector<ii>());
        //vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(K+1, oo)));
        int dp[N+1][N+1][K+1][2][2];
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < M ; ++i){
          int a, b, c;
          cin >> a >> b >> c;
          adj[a].push_back({b,c});
          adj[b].push_back({a,c});
          dp[a][b][0][0][0] = c;
          dp[b][a][0][0][0] = c;
          dp[a][b][1][1][1] = b <= A ? c-min(L,c) : oo;
          dp[b][a][1][1][1] = a <= A ? c-min(L,c) : oo;
        }
        for(int k = 1; k <= N ; ++k){
          for(int i = 1; i <= N ; ++i){
            for(int j = 1; j <= N ; ++j){
              for(int fastTravel = 0; fastTravel <= K ; ++fastTravel){
                for(int used = 0; used + fastTravel <= K ; ++used){           // i ->   k   ->   j
                  int tot = fastTravel + used;
                  if(used) min_self(dp[i][j][tot-1][1][1], dp[i][k][fastTravel][1][1] + dp[k][j][used-1][1][1]); // 1 1 1 1
                  min_self(dp[i][j][tot][1][1], dp[i][k][fastTravel][1][0] + dp[k][j][used][0][1]); // 1 0 0 1
                  if(used) min_self(dp[i][j][tot-1][0][0], dp[i][k][fastTravel][0][1] + dp[k][j][used-1][1][0]); // 0 1 1 0
                  min_self(dp[i][j][tot][0][0], dp[i][k][fastTravel][0][0] + dp[k][j][used][0][0]); // 0 0 0 0

                  min_self(dp[i][j][tot][1][0], dp[i][k][fastTravel][1][0] + dp[k][j][used][0][0]); // 1 0 0 0
                  min_self(dp[i][j][tot][0][1], dp[i][k][fastTravel][0][0] + dp[k][j][used][0][1]); // 0 0 0 1
                  if(used) min_self(dp[i][j][tot-1][0][1], dp[i][k][fastTravel][0][1] + dp[k][j][used-1][1][1]); // 0 1 1 1
                  if(used) min_self(dp[i][j][tot-1][1][1], dp[i][k][fastTravel][1][1] + dp[k][j][used-1][1][0]); // 1 1 1 0
                  //if(fastTravel) min_self(dp[i][j][tot][1][1], dp[i][k][used][1][1] + dp[k][i][fastTravel-1][1][1]);
                  //if(fastTravel)  min_self(dp[i][j][tot][0][1], dp[i][k][used-1][0][1] + dp[k][i][fastTravel][1][1]);
                }
              }
            }
          }
        }
        int ans = oo;
        for(int i = 0; i <= K ; ++i) {
          for(int j = 0; j < 2 ; ++j){
            for(int k = 0; k < 2 ; ++k){
              ans = min(ans, dp[N][1][i][j][k]);
              trace(i,j,k,dp[N][1][i][j][k]);
            }
          }
        }
        cout << ans << '\n';
    }
    return 0;
}
