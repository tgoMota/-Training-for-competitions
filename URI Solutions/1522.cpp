//https://www.urionlinejudge.com.br/judge/pt/problems/view/1522
//URI 1522 Jogo das Pilhas
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int N;
vector<int> st[3];
int memo[105][105][105];

bool multiple(int a){
    return ((a%3) == 0);
}

int solve(int a, int b, int c){
    if(a == N && b == N && c == N) return 1;
    int& ans = memo[a][b][c];
    if(ans != -1) return ans;
    int a1 = a < N && b < N && c < N && multiple(st[0][a] + st[1][b] + st[2][c]) && solve(a+1, b+1, c+1);//1A 1B 1C
    int a2 = a < N && multiple(st[0][a]) && solve(a+1, b, c); //1A
    int a3 = b < N && multiple(st[1][b]) && solve(a, b+1, c); //1B
    int a4 = c < N && multiple(st[2][c]) && solve(a, b, c+1); //1C
    int a5 = a < N && b < N && multiple(st[0][a]+st[1][b]) && solve(a+1, b+1, c); //1A 1B
    int a6 = a < N && c < N && multiple(st[0][a]+st[2][c]) && solve(a+1, b, c+1); //1A 1C
    int a7 = b < N && c < N && multiple(st[1][b]+st[2][c]) && solve(a,b+1,c+1);
    return ans = (a1 || a2 || a3 || a4 || a5 || a6 || a7);
}

int main(){
    while(scanf("%d", &N) && N){
        for(int i = 0; i < 3 ; ++i) st[i].clear();
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < 3 ; ++j){
                int a;
                scanf("%d", &a);
                st[j].push_back(a);
            }
        }
        memset(memo, -1, sizeof(memo));
        printf("%d\n", solve(0,0,0));
    }

    return 0;
}