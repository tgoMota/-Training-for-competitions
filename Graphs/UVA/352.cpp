//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288
//352 - The Seasonal War
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1}, dy[] = {0,1,1,1,0,-1,-1,-1};

int grid[26][26];

int floodfill(int indi, int indj, int c1, int c2, const int& sz){
    if(indi < 0 || indi >= sz || indj < 0 || indj >= sz) return 0;
    if(grid[indi][indj] != c1) return 0;
    grid[indi][indj] = c2;
    for(int i = 0; i < 8 ; ++i) floodfill(indi + dx[i], indj + dy[i], c1, c2, sz);
    return 1;
}

int main(){
    int l, img = 0;
    while(scanf("%d", &l) != EOF){
        string s[l];
        for(int i = 0; i < l ; ++i) cin >> s[i];
        for(int i = 0; i < l ; ++i)
            for(int j = 0; j < l ; ++j)
                grid[i][j] = s[i][j] - '0';
        int ans = 0;
        for(int i = 0; i < l ; ++i)
            for(int j = 0; j < l ; ++j)
                ans += floodfill(i,j,1,0,l);
        
        cout << "Image number " << ++img << " contains "<< ans << " war eagles.\n";
    }

    return 0;
}