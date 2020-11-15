//https://www.urionlinejudge.com.br/judge/pt/problems/view/1057
//URI 1057 Chegando Junto
//Wrong
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
int adj[11][11][11][11], n;
ii parent[11][11][11][11];
vector<string> grid;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

bool isValid(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == '#') return false;
    return true;
}
vector<ii> path[3];
void takePath(int ii, int ij, int ji, int jj, int idx){
    if(!(ii == ji && ij == jj)) takePath(ii,ij,parent[ii][ij][ji][jj].first, parent[ii][ij][ji][jj].second, idx);
    path[idx].push_back({ji,jj});
}

bool collisionPath(int p){
    for(int i = 0; ; ++i){
        if(i >= path[0].size() && i >= path[1].size()) return true;
        else if(i >= path[0].size() && i >= path[2].size()) return true;
        else if(i >= path[1].size() && i >= path[2].size()) return true;
        else if(i < path[0].size() && i < path[1].size() && path[0][i] == path[1][i]) {
            printf("retornou false em p = %d\n", p);
            return false;
        }
        else if(i < path[0].size() && i < path[2].size() && path[0][i] == path[2][i]) {
            printf("retornou false em p = %d\n", p);
            return false;
        }
        else if(i < path[1].size() && i < path[2].size() && path[1][i] == path[2][i]) {
            return false;
        }
    }
    return true;
}

void printPath(int idx){
    printf("\npath %d: ", idx);
    for(auto x : path[idx]) printf("{%d,%d} ", x.first, x.second);
    printf("\n\n");
}


int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> n;
        grid.resize(n);
        vector<ii> robots;
        vector<ii> targets;
        for(int i = 0; i < n ; ++i) 
            for(int j = 0; j < n ; ++j) 
                for(int k = 0; k < n ; ++k) 
                    for(int l = 0; l < n ; ++l) 
                        adj[i][j][k][l] = oo, parent[i][j][k][l] = {i,j};
        for(int i = 0; i < n ; ++i){
            cin >> grid[i];
            for(int j = 0; j < n ; ++j){
                if(grid[i][j] == 'A' || grid[i][j] == 'B' || grid[i][j] == 'C') robots.push_back({i,j});
                if(grid[i][j] == 'X') targets.push_back({i,j});
            }
        }
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < n ; ++j){
                if(!isValid(i,j)) continue;
                for(int k = 0; k < 4 ; ++k){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(!isValid(nx, ny)) continue;
                    adj[i][j][nx][ny] = 1;
                    adj[nx][ny][i][j] = 1;
                }
            }
        }

        for(int ki = 0; ki < n ; ++ki){
            for(int kj = 0; kj < n ; ++kj){
                for(int ii = 0; ii < n ; ++ii){
                    for(int ij = 0; ij < n ; ++ij){
                        for(int ji = 0; ji < n ; ++ji){
                            for(int jj = 0; jj < n ; ++jj){
                                if(adj[ii][ij][ki][kj] + adj[ki][kj][ji][jj] < adj[ii][ij][ji][jj]){
                                    adj[ii][ij][ji][jj] = adj[ii][ij][ki][kj] + adj[ki][kj][ji][jj];
                                    parent[ii][ij][ji][jj] = parent[ki][kj][ji][jj];
                                }
                            }
                        }
                    }
                }
            }
        }

    


        int ans = oo;
        int rai = robots[0].first;
        int raj = robots[0].second;
        int rbi = robots[1].first;    
        int rbj = robots[1].second;
        int rci = robots[2].first;
        int rcj = robots[2].second;

        int tai = targets[0].first;
        int taj = targets[0].second;
        int tbi = targets[1].first;
        int tbj = targets[1].second;
        int tci = targets[2].first;
        int tcj = targets[2].second;
        
        if(max({adj[rai][raj][tai][taj], adj[rbi][rbj][tbi][tbj], adj[rci][rcj][tci][tcj]}) <= ans){
            for(int i = 0; i < 3 ; ++i) path[i].clear();
            takePath(rai, raj, tai, taj, 0);
            takePath(rbi, rbj, tbi, tbj, 1);
            takePath(rci, rcj, tci, tcj, 2);
            printPath(0);
            printPath(1);
            printPath(2);
            if(!collisionPath(1)) ans = max({adj[rai][raj][tai][taj], adj[rbi][rbj][tbi][tbj], adj[rci][rcj][tci][tcj]});
        }
        if(max({adj[rai][raj][tai][taj], adj[rbi][rbj][tci][tcj], adj[rci][rcj][tbi][tbj]}) <= ans){ //a a, b b, c c
            for(int i = 0; i < 3 ; ++i) path[i].clear();
            takePath(rai, raj, tai, taj, 0);
            takePath(rbi, rbj, tci, tcj, 1);
            takePath(rci, rcj, tbi, tbj, 2);
            printPath(0);
            printPath(1);
            printPath(2);
            if(!collisionPath(2)) ans = max({adj[rai][raj][tai][taj], adj[rbi][rbj][tci][tcj], adj[rci][rcj][tbi][tbj]});
        }

        if(max({adj[rai][raj][tci][tcj], adj[rbi][rbj][tai][taj], adj[rci][rcj][tbi][tbj]}) <= ans){
            for(int i = 0; i < 3 ; ++i) path[i].clear();
            takePath(rai, raj, tci, tcj, 0);
            takePath(rbi, rbj, tai, taj, 1);
            takePath(rci, rcj, tbi, tbj, 2);
            printPath(0);
            printPath(1);
            printPath(2);
            if(!collisionPath(3)) ans = max({adj[rai][raj][tci][tcj], adj[rbi][rbj][tai][taj], adj[rci][rcj][tbi][tbj]});
        }

        if(max({adj[rai][raj][tci][tcj], adj[rbi][rbj][tbi][tbj], adj[rci][rcj][tai][taj]}) <= ans){
            for(int i = 0; i < 3 ; ++i) path[i].clear();
            takePath(rai, raj, tci, tcj, 0);
            takePath(rbi, rbj, tbi, tbj, 1);
            takePath(rci, rcj, tai, taj, 2);
            printPath(0);
            printPath(1);
            printPath(2);
            if(!collisionPath(4)) ans = max({adj[rai][raj][tci][tcj], adj[rbi][rbj][tbi][tbj], adj[rci][rcj][tai][taj]});
        }
        if(max({adj[rai][raj][tbi][tbj], adj[rbi][rbj][tai][taj], adj[rci][rcj][tci][tcj]}) <= ans){
            for(int i = 0; i < 3 ; ++i) path[i].clear();
            takePath(rai, raj, tbi, tbj, 0);
            takePath(rbi, rbj, tai, taj, 1);
            takePath(rci, rcj, tci, tcj, 2);
            printPath(0);
            printPath(1);
            printPath(2);
            if(!collisionPath(5)) ans = max({adj[rai][raj][tbi][tbj], adj[rbi][rbj][tai][taj], adj[rci][rcj][tci][tcj]});
        }
        if(max({adj[rai][raj][tbi][tbj], adj[rbi][rbj][tci][tcj], adj[rci][rcj][tai][taj]}) <= ans){
            for(int i = 0; i < 3 ; ++i) path[i].clear();
            takePath(rai, raj, tbi, tbj, 0);
            takePath(rbi, rbj, tci, tcj, 1);
            takePath(rci, rcj, tai, taj, 2);
            printPath(0);
            printPath(1);
            printPath(2);
            if(!collisionPath(6)) ans = max({adj[rai][raj][tbi][tbj], adj[rbi][rbj][tci][tcj], adj[rci][rcj][tai][taj]});
        }
        if(ans < oo ) cout << "Case " << ti << ": " << ans << '\n';
        else cout << "Case " << ti << ": trapped\n";
    }
    return 0;
}