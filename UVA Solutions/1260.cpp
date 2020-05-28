//https://www.urionlinejudge.com.br/judge/pt/problems/view/1260
//URI 1260 - Espécies de Madeira
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    fastio();
    int t;
    cin >> t;
    map<string,int> m;
    string k;
    getline(cin, k);
    getline(cin, k);
    for(int ti = 1; ti <= t ; ++ti){
        if(ti > 1) {
            cout << endl;
            m.clear();
        }
        string str;
        int cnt = 0;
        while(getline(cin, str) && str != ""){
            cnt++;
            m[str]++;
        }
        cout << fixed;
        cout.precision(4);
        for(auto x : m) cout << x.first.c_str() << " " << (x.second/(double)cnt)*100.00 << endl;
    }
    return 0;
}