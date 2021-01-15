//https://codeforces.com/contest/1335/problem/F
//F - Robots on a Grid
#include <bits/stdc++.h>
using namespace std;
vector<string> c,grid; 
typedef pair<int,int> ii;
//black => '0'
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        c.resize(n);
        grid.resize(n);
        vector<vector<ii>> parent(n, vector<ii>(m));
        for(int i = 0; i < n ; ++i) cin >> c[i];
        for(int i = 0; i < n ; ++i) {
            cin >> grid[i];
            for(int j = 0; j < m ; ++j){
                int r = i, c = j;
                if(grid[i][j] == 'U') r--;
                if(grid[i][j] == 'L') c--;
                if(grid[i][j] == 'D') r++;
                if(grid[i][j] == 'R') c++;
                parent[i][j] = {r,c};
            }
        }
        int logn = (int)log2(n*m)+1;
        for(int rep = 0; rep <= logn ; ++rep){
            vector<vector<ii>> tmp_parent(n, vector<ii>(m));
            for(int i = 0; i < n ; ++i){
                for(int j = 0; j < m ; ++j){
                    ii tmp = parent[i][j];
                    tmp_parent[i][j] = parent[tmp.first][tmp.second];
                }
            }
            parent = tmp_parent;
        }

        map<ii,bool> allReached, blacksReached;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                allReached[parent[i][j]] = true;
                if(c[i][j] == '0') blacksReached[parent[i][j]] = true;
            }
        }

        int robots = (int)allReached.size(), blacks = (int)blacksReached.size();
        printf("%d %d\n", robots, blacks);
    }
    return 0;
}