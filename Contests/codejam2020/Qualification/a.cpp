#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

typedef long long ll;

int main(){
    int t, n;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> n;
        int m[n][n], k = 0, r = 0, c = 0;
        map<pair<int,int>, int> row, col;
        unordered_map<int, bool> vstrow, vstcol;

        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < n ; ++j) {
                cin >> m[i][j];
                if(i == j) k+=m[i][j];
                if(vstrow.find(i) == vstrow.end() && row.find(make_pair(i, m[i][j])) != row.end()){
                    r++;
                    vstrow[i] = true;
                }
                if(vstcol.find(j) == vstcol.end() && col.find(make_pair(j, m[i][j])) != col.end()) {
                    c++;
                    vstcol[j] = true;
                }
                row[make_pair(i, m[i][j])] = 1;
                col[make_pair(j, m[i][j])] = 1;
            }
        }

        printf("Case #%d: %d %d %d\n", ti, k, r, c);

    }

    return 0;
}