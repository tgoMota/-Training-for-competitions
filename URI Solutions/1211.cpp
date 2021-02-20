//https://www.urionlinejudge.com.br/judge/pt/problems/view/1211
//URI 1211 - Lista Telefônica Econômica
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
int n;

struct Node{
  Node* m[10];
  bool end;
  Node(){
    end = false;
    for(int i = 0; i < 10 ; ++i) m[i] = NULL;
  }
};

struct Trie{
  Node* root;
  Trie(){
    root = new Node();
  }

  int insert(string& s){
    const int N = (int)s.size();
    Node* cur = root;
    int ans = 0;
    for(int i = 0; i < N ; ++i){
      char ch = s[i]-'0';
      if(cur->m[ch] == NULL){
        Node* nw = new Node();
        cur->m[ch] = nw;
        cur = nw;
      }else{
        cur = cur->m[ch];
        ans++;
      }
    }
    cur->end = true;
    return ans;
  }

  void clear(Node *cur){
    if(cur == NULL) return;
    for(int i = 0; i < 10 ; ++i){
      clear(cur->m[i]);
    }
    delete cur;
  }

  void clearAll(){
    clear(root);
  }

};

int main(){
    while(cin >> n){
      int ans = 0;
      Trie *t = new Trie();
      for(int i = 0; i < n ; ++i){
        string s;
        cin >> s;
        ans += t->insert(s);
      }
      t->clearAll();
      cout << ans << '\n';
    }
    return 0;
}
