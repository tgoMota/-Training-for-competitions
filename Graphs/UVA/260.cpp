#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1}, dy[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int indi, int indj, const char& color, const char& color2 ,string* grid ,int& sz){
    if(indi < 0 || indi >= sz || indj < 0 || indj >= sz) return 0;
    if(grid[indi][indj] != color) return 0;
    if(color == 'w' && indj == sz-1) return 1;
    if(color == 'b' && indi == sz-1) return 1;
    int ans = 0;
    grid[indi][indj] = color2;
    for(int d = 0; d < 8 ; ++d) ans = max(ans,floodfill(indi+dx[d], indj+dy[d],color,color2,grid, sz));
    return ans;
}

int main(){
    int t = 0, q;
    while(scanf("%d", &q) && q){
        string row[q], cpy[q];
        for(int i = 0; i < q ; ++i) cin >> row[i];
        cout << ++t << " " << (floodfill(0,0,'w','k', row, q) ? 'W' : 'B' )<< endl;
    }

    return 0;
}