//https://codeforces.com/contest/707/problem/E
//E. Garlands
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<vector<pair<ll,ii>>> garland;
vector<vector<ll>> fen;
vector<bool> isTurned;
vector<bool> needChange;
int R, C, K;

void add(int i, int j, ll val){
    for(int x = i; x <= R ; x += x & -x){
        for(int y = j; y <= C ; y += y & -y){
            fen[x][y] += val;
        }
    }
}

ll query(int i, int j){
    ll sum = 0LL;
    for(int x = i; x > 0 && x <= R ; x -= x & -x){
        for(int y = j; y > 0 && y <= C ; y -= y & -y){
            sum += fen[x][y];
        }
    }
    return sum;
}

ll query(int x1, int y1, int x2, int y2){
    return query(x2,y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1,y1-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K; 
    garland.assign(K+1, vector<pair<ll,ii>>());
    isTurned.assign(K+1, true);
    needChange.assign(K+1, true);
    fen.assign(R+1, vector<ll>(C+1, 0LL));
    
    for(int i = 1; i <= K ; ++i){
        int len;
        cin >> len;
        for(int j = 0; j < len ; ++j){
            int a, b;
            ll c;
            cin >> a >> b >> c;
            garland[i].push_back({c,{a,b}});
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q ; ++i){
        string str;
        cin >> str;
        if(str == "ASK"){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            for(int j = 1; j <= K ; ++j){
                if(needChange[j]){
                    ll mul = isTurned[j] ? 1LL : -1LL;
                    for(auto g : garland[j]){
                        ll w = g.first;
                        int x = g.second.first;
                        int y = g.second.second;
        
                        add(x,y,w*mul);
                    }
                    needChange[j] = false;
                }
            }
            cout << query(a,b,c,d) << '\n';
        }else{
            int a;
            cin >> a;
            isTurned[a] = 1-isTurned[a];
            needChange[a] = 1-needChange[a];
        }
    }
    return 0;
}