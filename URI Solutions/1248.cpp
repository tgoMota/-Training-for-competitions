//URI 1248 - Plano de Dieta
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1248
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    int t;
    cin >> t;
    cin.ignore();
    for(int ti = 1; ti <= t ; ++ti){
        string a, b, c;
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);
        map<char, int> cnt;
        bool cheat = false;
        for(char c : a) cnt[c] = 0;
        for(char c : b){
          if(cnt.find(c) == cnt.end() || cnt[c] > 0){
            cheat = true;
            break;
          }
          cnt[c]++;
        }
        for(char ch : c){
          if(cnt.find(ch) == cnt.end() || cnt[ch] > 0){
            cheat = true;
            break;
          }
          cnt[ch]++;
        }

        if(cheat) cout << "CHEATER\n";
        else{
          for(auto x : cnt){
            if(x.second == 0) cout << x.first;
          }
          cout << '\n';
        }
    }
    return 0;
}

