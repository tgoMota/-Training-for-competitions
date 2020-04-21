
#include <bits/stdc++.h>
using namespace std;
int ro, co, dx[] = {1,1,0,-1,-1,-1,0,1}, dy[] = {0,1,1,1,0,-1,-1,-1};
int grid[101][101];

int floodfill(int r, int c, const int c1, const int c2, const int szr, const int szc){
    if(r < 0 || c < 0 || r >= szr || c >= szc) return 0;
    if(grid[r][c] != c1) return 0;
    grid[r][c] = c2;
    int ans = 1;
    for(int i = 0; i < 8 ; ++i) ans+=floodfill(r+dx[i], c+dy[i], c1, c2, szr, szc);
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &ro, &co);
        string row;
        int i = 0, szc;
        while(getline(cin, row)){
            if(!isdigit(row[0])) continue;
            szc = row.size();
            for(int j = 0; j < row.size() ; ++j) grid[i][j] = row[j] - '0';
            i++;
        }
        
        int ans = floodfill(ro-1,co-1, 0, 1, i, szc);
        printf("%d\n", ans);
        if(T){
            printf("\n");
            getline(cin, row);
        }
    }

    return 0;
}