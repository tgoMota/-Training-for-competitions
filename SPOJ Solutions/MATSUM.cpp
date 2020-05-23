//https://www.spoj.com/problems/MATSUM/
//SPOJ MATSUM - Matrix Summation
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> fen;
int N;
void add(int i, int j, int val){
    for(int x = i+1; x > 0 &&  x <= N ; x += x & -x){
        for(int y = j+1; y > 0 && y <= N ; y += y & -y){
            fen[x][y] += val;
        }
    }
}

ll query(int i, int j){
    ll sum = 0LL;
    for(int x = i+1 ; x > 0 && x <= N ; x-= x & -x){
        for(int y = j+1 ; y > 0 && y <= N ; y-= y & -y){
            sum += fen[x][y];
        }
    }
    return sum;
}

ll query(int x1, int y1, int x2, int y2){
    return query(x2,y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        fen.assign(N+1, vector<ll>(N+1, 0LL));
        string str;
        while(cin >> str && str != "END"){
            int a, b, c, d;
            if(str == "SUM"){
                cin >> a >> b >> c >> d;
                cout << query(a, b, c, d) << '\n';
            }else{
                cin >> a >> b >> c;
                add(a, b, c-query(a,b,a,b));
            }
        }
        cout << '\n';
    }
    return 0;
}