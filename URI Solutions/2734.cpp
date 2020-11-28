//https://www.urionlinejudge.com.br/judge/pt/problems/view/2734
//URI 2734 - Trocando Presentes
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
const int MAXN = 105;
int memo[MAXN*2][MAXN][10*MAXN];
int totalSum;
int minAbs(int a, int b){
  return abs(a) < abs(b) ? a : b;
}
int solve(int idx, int tookA, int sum, const int N, vector<int>& toys){
  if(2*tookA == N) return abs(totalSum-2*sum);
  if(2*tookA > N || idx == N) return oo;
  int& ans = memo[idx][tookA][sum];
  if(ans != -1) return ans;
  int A = solve(idx+1, tookA+1, sum+toys[idx], N, toys);
  int B = solve(idx+1, tookA, sum, N, toys);
  return ans = min(A, B);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        n*=2;
        vector<int> toys(n);
        totalSum = 0;
        for(int i = 0; i < n ; ++i) {
          scanf("%d", &toys[i]);
          totalSum+=toys[i];
        }

        memset(memo, -1, sizeof(memo));
        printf("%d\n", solve(0,0,0,n,toys));
    }
    return 0;
}