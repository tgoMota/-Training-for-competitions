//https://www.urionlinejudge.com.br/judge/pt/problems/view/1167
//URI 1167 - Acampamento de Férias
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
struct p{
  string name;
  int num;
  p(){}
  p(string _name, int _num){
    name = _name;
    num = _num;
  }
};

list<p>::iterator getNext(list<p>& a, list<p>::iterator &it, int direction){
  auto toEnd = a.end();
  toEnd--;
  if(direction) return next(it) == a.end() ? a.begin() : next(it);
  else return it == a.begin() ? toEnd : prev(it);
}

int main(){
    fastio();
    list<p> circle;
    int n;
    while(cin >> n && n){
      circle.clear();
      string name;
      int num;
      for(int i = 0; i < n ; ++i){
        cin >> name >> num;
        circle.push_back(p(name, num));
      }

      auto it = circle.begin();
      int val = (*it).num;
      int direction = val%2; //0 -> clockwise
      while(circle.size() > 1){
        const int sz = circle.size();
        val%=sz;
        while(val-->0){
          it = getNext(circle,it, direction);
        }
        val = (*it).num;
        direction = val%2;
        auto it2 = it;
        it = getNext(circle, it, direction);
        val--;
        circle.erase(it2);
      }
      cout << "Vencedor(a): " << (*circle.begin()).name << '\n';
    }
    return 0;
}