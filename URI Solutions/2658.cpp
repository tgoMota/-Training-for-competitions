//https://www.urionlinejudge.com.br/judge/pt/problems/view/2658
//URI 2658 - Acordes Intergaláticos
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
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
struct Seg{
    vector<vector<int>> t;
    vector<int> lz;
    vector<int> tmpPush;
    Seg(){}
    Seg(int n){ 
        t.assign(4*n, vector<int>(9, 0));
        lz.assign(4*n,0);
        tmpPush.assign(9,0);
    }

    void push(int i, int l, int r){
        if(!lz[i]) return;
        for(int j = 0; j < 9 ; ++j) tmpPush[(j+lz[i])%9]=t[i][j];
        t[i].swap(tmpPush);
        if(l != r){
            lz[2*i]+=lz[i];
            lz[2*i+1]+=lz[i];
        }
        lz[i] = 0;
    }

    void query(int i, int  l, int r, int ql, int qr, vector<int>& ans){
        push(i,l,r);
        if(ql > r || qr < l) return;
        if(ql <= l && qr >= r){
            for(int j = 0; j < 9 ; ++j){
                ans[j] += t[i][j];
            }
            return;
        }
        int m = (l + r) >> 1;
        query(2*i, l, m, ql, qr, ans);
        query(2*i+1, m+1, r, ql, qr, ans);
    }

    void update(int i, int l, int r, int ql, int qr, const int f){
        push(i,l,r);
        if(r < ql || l > qr) return;
        if(ql <= l && qr >= r){
           lz[i]+=f;
           push(i,l,r);
           return;
        }

        int m = (l + r) >> 1;
        update(2*i, l, m, ql, qr, f);
        update(2*i+1, m+1, r, ql, qr, f);
        for(int j = 0; j < 9 ; ++j){
            t[i][j]=t[2*i][j]+t[2*i+1][j];
        }
     }

     void build(int i, int l, int r){
         if(l == r){
             t[i][1] = 1;
             return;
         }
         int m = (l + r) >> 1;
         build(2*i, l, m);
         build(2*i+1, m+1, r);
         t[i][1] += t[2*i][1]+t[2*i+1][1];
     }

     void printNotes(int N){
        for(int i = 0; i < N ; ++i){
            vector<int> ans(9,0);
            query(1, 0, N-1, i, i, ans);
            for(int j = 0; j < 9 ; ++j){
                if(ans[j]) cout << j << '\n';
            }
        }
     }
};

int main(){
    fastio();
    int N, Q;
    cin >> N >> Q;
    Seg sg(N+5);
    sg.build(1, 0, N-1);
    auto getMax = [&](ii a, ii b){
        if(a.first != b.first) return a.first > b.first ? a : b;
        return a.second > b.second ? a : b;
    };
    for(int qi = 0; qi <  Q ; ++qi) {
      int a, b;
      cin >> a >> b;
      vector<int> ans(9, 0);
      sg.query(1, 0, N-1, a, b, ans);
      ii best = {0,0};
      for(int j = 0; j < 9 ; ++j) best = getMax(best, {ans[j], j});
      sg.update(1, 0, N-1, a, b, best.second);
    }

    sg.printNotes(N);
    return 0;
}
