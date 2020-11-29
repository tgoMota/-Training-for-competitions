//https://www.urionlinejudge.com.br/judge/pt/problems/view/1112
//URI 1112 - Schweisen
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int N, M, P;
vector<vector<int>> ft;
void init(){
  ft.assign(N+1, vector<int>(M+1, 0));
}

int get(int R, int C){
  int idxi = R+1, sum = 0;
  while(idxi > 0){
    int idxj = C+1;
    while(idxj > 0){
      sum+=ft[idxi][idxj];
      idxj -= idxj & -idxj;
    }
    idxi -= idxi & -idxi;
  }
  return sum;
}

void update(int R, int C, int val){
  int idxi = R+1;
  while(idxi <= N){
    int idxj = C+1;
    while(idxj <= M){
      ft[idxi][idxj] += val;
      idxj += idxj & -idxj;
    }
    idxi += idxi & -idxi;
  }
}
int query(int ra, int ca, int rb, int cb){
  return (get(max(ra,rb), max(ca,cb)) - get(min(ra,rb)-1, max(ca,cb)) - get(max(ra,rb), min(ca,cb)-1) + get(min(ra,rb)-1, min(ca,cb)-1))*P;
}

int main(){
    fastio();
    while(cin >> N >> M >> P && N+M+P){
      init();
      int q;
      cin >> q;
      for(int i = 0; i < q;  ++i){
        string A;
        cin >> A;
        if(A == "A"){
          int a, b, c;
          cin >> a >> b >> c;
          update(b, c, a);
        }else{
          int a, b, c, d;
          cin >> a >> b >> c >> d;
          cout << query(a,b,c,d) << '\n';
        }
      }
      cout << '\n';
    }
    return 0;
}