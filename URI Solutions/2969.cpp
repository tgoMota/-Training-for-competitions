//https://www.urionlinejudge.com.br/judge/en/problems/view/2969
//URI 2969 - Interplanetary
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
const int NAX = 405;
typedef pair<int,int> ii;
vector<ii> t;
int floyd[2][NAX][NAX],n, r;
vector<int> answer;
struct query{
    int a, b, d, id;
    query(int _id, int _a, int _b){
        id = _id;
        a = _a;
        b = _b;
    }
};
vector<query> querys[2][NAX];

int main(){
    scanf("%d%d", &n, &r);
    t.resize(n);
    for(int i = 0; i < n ; ++i) {
      scanf("%d", &t[i].first);
      t[i].second = i+1;
    }

    memset(floyd, 0x3f, sizeof(floyd));
    for(int i = 0; i < r ; ++i){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      floyd[0][a][b] = floyd[0][b][a] = c;
      floyd[1][a][b] = floyd[1][b][a] = c;
    }
    
    int q;
    scanf("%d", &q);
    for(int idx = 1; idx <= q ; ++idx){
      int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      querys[d][c].push_back({idx,a,b});
    }
    sort(t.begin(), t.end());
    int k = 1;
    answer.resize(q+1);
    for(int z = 0; z < n ; ++z){
        if(z) k+= t[z].first != t[z-1].first;
        int u = t[z].second;
        for(int i = 1; i <= n ; ++i){
          for(int j = 1; j <= n ; ++j){
            floyd[0][i][j] = min(floyd[0][i][j], floyd[0][i][u] + floyd[0][u][j]);
          }
        }

        for(query& x : querys[0][k]){
            answer[x.id] = floyd[0][x.a][x.b] >= oo ? -1 : floyd[0][x.a][x.b];
        }
    }

    for(; k <= n ; ++k){
        for(query& x : querys[0][k]){
            answer[x.id] = floyd[0][x.a][x.b] >= oo ? -1 : floyd[0][x.a][x.b];
        }
    }

    sort(t.begin(), t.end(), greater<ii>());
    k = 1;
    for(int z = 0; z < n ; ++z){
        if(z) k+= t[z].first != t[z-1].first;
        int u = t[z].second;
        for(int i = 1; i <= n ; ++i){
          for(int j = 1; j <= n ; ++j){
            floyd[1][i][j] = min(floyd[1][i][j], floyd[1][i][u] + floyd[1][u][j]);
          }
        }

        for(query& x : querys[1][k]){
            answer[x.id] = floyd[1][x.a][x.b] >= oo ? -1 : floyd[1][x.a][x.b];
        }
    }

    for(; k <= n ; ++k){
        for(query& x : querys[1][k]){
            answer[x.id] = floyd[1][x.a][x.b] >= oo ? -1 : floyd[1][x.a][x.b];
        }
    }

    for(int i = 1; i <= q ; ++i){
        printf("%d\n", answer[i]);
    }



    return 0;
}
