#include <bits/stdc++.h>
using namespace std;

#define b begin()
#define e end()
#define pb push_back
#define mk make_pair
#define oo 100010
#define s second
#define f first

vector<int> Pai,Quarda;
int jogs,unions,consu,maximo,g,h;

int find(int n){
    if(Pai[n] == n) return n;
    return Pai[n] = find(Pai[n]);
}

void join(int x,int y){
    int fa = find(x),fb = find(y);
    if(fa != fb){
        Pai[fb] = fa;
    }
}

int main() {

    Quarda.pb(0);
    while(cin >> jogs >> unions >> consu){
        if(jogs > maximo){
            for(int k=maximo+1;k<=jogs;k++)
            Quarda.pb(k);
            maximo = jogs;
        }

        Pai = Quarda;
        for(int k=0;k<unions;k++){
            cin >> g >> h;
            join(g,h);
        }

        for(int k=0;k<consu;k++){
            cin >> g >> h;
            if(find(g) == find(h)) cout << "S\n";
            else cout << "N\n";
        }
        cout << endl;
    }

    return 0;
}
