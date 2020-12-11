//https://www.urionlinejudge.com.br/judge/pt/problems/view/1058
//URI1210 - Produção Ótima de Ótima Vodka
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
vector<int> ci, vi;
int memo[2005][2005];

int solve(int year, int old, const int N ,const int M, const int P){
  if(year == N) return 0;
  int& ans = memo[year][old];
  if(ans != -1) return ans;
  int A = (old == M-1) ? oo : solve(year+1, old+1, N, M, P) + ci[old+1];
  int B = solve(year+1, 0, N, M, P) + P - vi[old] + ci[0];
  return ans = min(A,B);
}

void rec(int year, int old, const int N, const int M, const int P, int cnt){
  if(year == N){
    if(!cnt) printf("0\n");
    else printf("\n");
    return;
  }
  int A = (old == M-1) ? oo : solve(year+1, old+1, N, M, P) + ci[old+1];
  int B = solve(year+1, 0, N, M, P) + P - vi[old] + ci[0];
  if(B<=A) {
    if(cnt) printf(" ");
    printf("%d", year+1);
    rec(year+1, 0, N, M, P, cnt+1);
  }
  else{
    rec(year+1, old+1, N, M, P, cnt);
  }
}

int main(){
    int N, I, M, P;
    while(scanf("%d%d%d%d", &N, &I, &M, &P)!=EOF){
      ci.resize(M);
      vi.resize(M);
      for(int i = 0; i < M ; ++i) scanf("%d", &ci[i]);
      for(int i = 0; i < M ; ++i) scanf("%d", &vi[i]);
      memset(memo, -1, sizeof(memo));
      printf("%d\n", solve(0, I-1, N, M, P));
      rec(0,I-1,N,M,P,0);
    }
    return 0;
}