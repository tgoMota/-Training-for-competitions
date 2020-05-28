#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
vector<string> grid;
int n;

bool check(int i, int j){
    if(j == n-1 || i == n-1) return true;
    if(grid[i+1][j] == '1' || grid[i][j+1] == '1') return true;
    return false;
}

bool checkAll(){
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < n ; ++j){
            if(grid[i][j] == '1' && !check(i,j)) {
                return false;
            }
        }
    }
    return true;
}
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> n;
        grid.resize(n);
        for(int i = 0; i < n ; ++i) cin >> grid[i];

        if(checkAll()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}