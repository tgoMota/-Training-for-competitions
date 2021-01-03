#include <bits/stdc++.h>
using namespace std;

int dy[] = {0,1,-1}, dx[] = {-1,0,0};
vector<string> grid;
string toReach = "@IEHOVA#";
vector<string> answer;
int back(int i, int j, int cnt, const int N, const int M){
    if(grid[i][j] != toReach[cnt]) return 0;
    if(grid[i][j] == '#') return 1;
    int ans = 0;
    for(int p = 0; p < 3 ; ++p){
        int ix = i+dx[p], iy = j+dy[p];
        if(ix < 0 || ix >= N || iy < 0 || iy >= M) continue;
        ans = back(ix,iy, cnt+1, N, M);
        if(ans){
            if(p == 0) answer.push_back("forth");
            else if(p == 1) answer.push_back("right");
            else answer.push_back("left"); 

            break;
        }
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        grid.clear();
        pair<int,int> posIni;
        for(int i = 0; i < n ; ++i){
            string s;
            cin >> s;
            grid.push_back(s);
            for(int j = 0; j < m ; ++j){
                if(s[j] == '@') posIni = {i,j};
            }
        }
        answer.clear();
        back(posIni.first, posIni.second, 0, n, m);
        reverse(answer.begin(), answer.end());
        for(int i = 0; i < (int)answer.size() ; ++i){
            if(i) printf(" ");
            printf("%s", answer[i].c_str());
        }
        printf("\n");
    }
    return 0;
}
