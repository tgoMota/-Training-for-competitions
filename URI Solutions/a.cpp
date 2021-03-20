//https://www.urionlinejudge.com.br/judge/pt/problems/view/1868
//URI 186 - Espiral Quadrada
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//CHECK THE CONSTRAINTS, PLEASE
int dy[] = {1,0,-1,0}, dx[] = {0,-1,0,1};
void print(vector<string>& grid, int posx, int posy){
  grid[posx][posy] = 'X';
  for(string& x : grid) cout << x << '\n';
  grid[posx][posy] = 'O';
  cout << "@\n";
}
int main(){
    fastio();
    int n;
    while(cin >> n && n){
      vector<int> ind = {1,1,1,1};
      vector<string> grid(n, string(n, 'O'));
      int posx = (n-1)/2, posy = posx, cnt = 1;
      print(grid, posx, posy);
      bool ok = false;
      while(!ok && cnt < n*n){
        for(int d = 0; d < 4 && !ok ; ++d){
          for(int i = 0; i < ind[d] ; ++i){
            posx += dx[d], posy += dy[d];
            print(grid, posx, posy);
            if(++cnt == n*n){
              ok = true;
              break;
            }
          }
          ind[d]++;
          ind[(d+2)%4]++;
        }
      }
    }
    return 0;
}

