//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410
//UVA 469 - Wetlands of Florida

#include <bits/stdc++.h>
using namespace std;

int n, m, grid[100][100], nc;
int dx[] = {1,1,0,-1,-1,-1,0,1}, dy[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int indi, int indj, int r, int w){
    if(indi >= n || indi < 0 || indj >= m || indj < 0) return 0;
    if(grid[indi][indj] != r) return 0;
    int ans = 1;
    grid[indi][indj] = w;
    for(int d = 0; d < 8 ; ++d) ans+= floodfill(indi+dx[d], indj+dy[d], r, w);
    return ans;
}

int main(){
    cin >> nc;
    cin.ignore(2);
    string s;
    while(nc--){
        n = m = 0;
        while(getline(cin, s) && (s[0]=='W' || s[0] == 'L')){
            for(int i = 0; i < s.size() ; ++i) grid[n][i] = (s[i] == 'L')? 1:2; // L = 1 and W = 2
            n++;
            m = s.size();
        }
        do{
            int a, b;
            sscanf(s.c_str(), "%d %d", &a, &b);
            a--, b--;
            printf("%d\n", floodfill(a,b,2,3)); 
            floodfill(a,b,3,2);
        }while(getline(cin,s) && s!="");
        if(nc) cout << endl;
    }

    return 0;
}