#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int n;
typedef long long ll;
int m[501][501];

bool can(int& k){
    int r = 0, c = 0;
    k = 0;
    map<pair<int,int>, int> row, col;
    for(int i = 0; i < n ; ++i){
            for(int j = 0; j < n ; ++j) {
                if(i == j) k+=m[i][j];
                if(row.find(make_pair(i, m[i][j])) != row.end()){
                    r++;
                    return false;
                }
                if(col.find(make_pair(j, m[i][j])) != col.end()) {
                    c++;
                    return false;
                }
                row[make_pair(i, m[i][j])] = 1;
                col[make_pair(j, m[i][j])] = 1;
            }
        }
    return true;
}

int main(){
    int t, n, k;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> n >> k;
        for(int i = 0; i < n ; ++i)
            for(int j = 0; j < n ; ++j) cin >> m[i][j];
        
        printf("Case #%d: %d %d %d\n", ti, 0,0,0);
    }

    return 0;
}