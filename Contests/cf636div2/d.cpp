#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        vector<string> grid(9);
        for(int i = 0; i < 9 ; ++i){
            cin >> grid[i];
            for(int j = 0; j < 9 ; ++j) if(grid[i][j] == '1') grid[i][j] = '3';
        }
        printf("\n\n");
        for(int i = 0; i < 9 ; ++i) printf("%s\n", grid[i].c_str());
    }
    return 0;
}