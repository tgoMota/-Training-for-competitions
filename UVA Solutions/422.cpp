#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,1,1,1,0,-1,-1,-1}, dy[] = {-1,-1,0,1,1,1,0,-1};

bool contain(string& query, vector<string>& v, const int N){
    for(int i = 0; i < N ; ++i){
        for(int j = 0; j < N ; ++j){
            for(int k = 0; k < 8 ; ++k){
                int x = i, y = j, len = 0;
                const int M = query.size();
                while(v[x][y] == query[len]){
                    if(len == M-1){
                        printf("%d,%d %d,%d\n", i+1, j+1, x+1, y+1);
                        return true;
                    }
                    x+=dx[k];
                    y+=dy[k];
                    len++;
                    if(x < 0 || y < 0 || x >= N || y >= N) break;
                }
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n ; ++i) cin >> v[i];

    string query;
    while(cin >> query && query != "0"){
        if(!contain(query, v, n)) printf("Not found\n");
    }
    return 0;
}