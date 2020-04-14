#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int N = 105;
int vx[] = {0,1}, vy[] = {1,0}, h, w;
int grid[N][N];
int memo[N][N];

int solve(int posi, int posj){
    if(posi < 0 || posj < 0 || posi >= h || posj >= w) return oo;
    if(posi == h-1 && posj == w - 1) return grid[posi][posj] == 0;
    int& ans = memo[posi][posj];
    if(ans != -1) return ans;
    ans = oo;
    for(int i = 0; i < 2 ; ++i) {
        ans = min(ans, solve(vx[i] + posi, vy[i] + posj) + (grid[posi][posj] == 0));
    }
    return ans;
}

int main(){
    cin >> h >> w;
    string s;
    for(int i = 0; i < h ; ++i){
        cin >> s;
        for(int j = 0; j < w ; ++j){
            grid[i][j] = (s[j] == '.');
        }
    }

    memset(memo, -1, sizeof(memo));
    printf("%d\n", solve(0,0));


    return 0;
}