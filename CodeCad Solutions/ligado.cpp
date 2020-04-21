//http://www.codcad.com/problem/118

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100100];

int temPonte(int a, int b){
   for(int i : adj[a]){
       if(i == b) return 1;
   }
   return 0;
}

int main(){
    int n, m, k, t, a, b;
    cin >> n >> m;
    for(int i = 0; i < m ; ++i){
        cin >> t >> a >> b;
        if(t == 0){
            cout << temPonte(a, b) << endl;
        }else{
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    
    return 0;
}
