#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxN = 1005;
vector<string> grid;
vector<bool> placedRow;
vector<bool> placedCol;
int main(){
    fastio();
    int t = 1;
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        cin >> n >> m;
        grid.resize(n);
        placedCol.assign(m, false);
        placedRow.assign(n, false);
        for(int i = 0; i < n ; ++i){
            cin >> grid[i];
            for(int j = 0; j < m ; ++j){

            }
        }
    }
    return 0;
}