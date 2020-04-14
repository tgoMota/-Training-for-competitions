// #include <bits/stdc++.h>
// using namespace std;
// #define oo 99999.99
// vector<pair<int,double> > p;
// double memo[1<<12][51];
// vector<pair<int,double> > adj[51];

// double solve(int mask, int house){
//     if(mask == 0 && house == 0) return 0.0;
//     double& ans = memo[mask][house];
//     if(ans != -1) return ans;
//     ans = -oo;
//     for(auto x : adj[house]){
//         int d = x.second, next = x.first;
//         ans = max(ans, p[next].second-d + solve(p[next].first >= 0 ? (mask - (1 << p[next].first)) : mask, next));
//     }
//     return ans;
// }

// int main(){
//     int T;
//     scanf("%d", &T);
//     while(T--){
//         int nh, nr, P;
//         scanf("%d%d", &nh, &nr);
//         for(int i = 0; i < nr ; ++i){
//             int a, b;
//             double c;
//             scanf("%d%d%lf", &a, &b, &c);
//             adj[a].push_back(make_pair(b,c));
//         }
//         scanf("%d", &P);
//         p.assign(nh+1, {-1,0.0});
//         for(int i = 0; i < P ; ++i){
//             int a;
//             double b;
//             scanf("%d%lf", &a, &b);
//             p[a] = make_pair(i,b);
//         }

//         for(int i = 0; i < (1<<12) ; ++i)
//             for(int j = 0; j < 51 ; ++j)
//                 memo[i][j] = -1;
        
//         printf("Daniel can save $%.2lf\n", solve((1<<P)-1, 0));

//     }
    

//     return 0;
// }