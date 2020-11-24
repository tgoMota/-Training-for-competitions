// #include <bits/stdc++.h>
// using namespace std;
// #define oo 0x3f3f3f3f
// #define ooLL 0x3f3f3f3f3f3f3f3f
// #define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
// #define debug(x) cout << "DONT CRY " << x << endl
// #define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
// const int mod = 1e9+7;
// typedef long long ll;
// typedef long double ld;
// typedef unsigned long long ull;
// typedef pair<int,int> ii;
// vector<int> v;
// vector<vector<int>> adj;
// int n, m;
// set<ii, greater<ii>> s;
// vector<bool> vst;
// bool exist[205][205];
// bool removed[205];

// int dfs(int u){
//     if(removed[u]) return 0;
//     int ans = 0;
//     for(int x : adj[u]){
//         if(!removed[x]) ans++;
//     }
//     return ans;
// }


// int main(){
//     int t;
//     scanf("%d", &t);
//     for(int ti = 1; ti <= t ; ++ti){
//         v.clear();
//         memset(exist, false, sizeof(exist));
//         memset(removed, false, sizeof(removed));
//         scanf("%d", &n);
//         for(int i = 0; i < n ; ++i){
//             int a;
//             scanf("%d", &a);
//             v.push_back(a);
//         }
//         scanf("%d", &m);
//         for(int i = 0; i < m ; ++i){
//             int a;
//             scanf("%d", &a);
//             v.push_back(a);
//         }
//         adj.assign(n+m, vector<int>());
//         for(int i = 0; i < n ; ++i){
//             for(int j = n; j < n+m ; ++j){
//                 if((v[j]%v[i]) == 0) {
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                     exist[i][j] = true;
//                     exist[j][i] = true;
//                 }
//             }
//         }

//         int cnt = 0;
//         while(1){
//             s.clear();
//             for(int i = 0; i < n+m ; ++i){
//                 s.insert({dfs(i),i});
//             }
//             auto x = *s.begin();
//             if(x.first == 0) break;
//             removed[x.second] = true;
//             cnt++;
//         }

//         printf("Case %d: %d\n", ti, cnt);
//     }
//     return 0;
// }