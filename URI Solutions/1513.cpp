//https://www.urionlinejudge.com.br/judge/pt/problems/view/1513
//URI 1513 - Cavalo
//Runtime Error
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int n, m, k, dx[]={2,2,-2,-2,1,1,-1,-1}, dy[] = {1,-1,1,-1,2,-2,2,-2};
vector<string> grid;
//int memo[101][101][1<<15];
map<pair<int,ii>, int> mp;
int solve(int i, int j, int mask, int posi, int posj){
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#') return oo;
    if(mask == 0 && i == posi && j == posj) return 0;
    if(mp.find({i,{j,mask}}) != mp.end()) return mp[{i,{j,mask}}];
    int ans = oo;
    for(int idx = 0; idx < 8 ; ++idx){
        int x = dx[idx] + i;
        int y = dy[idx] + j;
        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#') continue;
        int digit = grid[x][y] - '0';
        int newMask = isdigit(grid[x][y]) && (mask & (1 << digit)) ? mask ^ (1 << digit) : mask;
        ans = min(ans,1+solve(x, y, newMask, posi, posj));
    }
    return mp[{i,{j,mask}}] = ans;
}


int main(){
    fastio();
    while(cin >> n >> m >> k && n + m + k){
        grid.resize(n);
        int posi, posj;
        for(int i = 0, cnt = 0; i < n ; ++i){
            cin >> grid[i];
            for(int j = 0; j < m ; ++j) {
                if(grid[i][j] == 'C') posi = i, posj = j;
                if(grid[i][j] == 'P') grid[i][j] = '0' + cnt++;
            }
        }

         cout << solve(posi,posj,(1<<k)-1, posi, posj) << '\n';
    }

    return 0;
}