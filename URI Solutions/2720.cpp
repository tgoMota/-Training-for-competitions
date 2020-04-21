//https://www.urionlinejudge.com.br/judge/pt/problems/view/2720
//URI 2720 - Presentes Grandes
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    else return a.second > b.second;
}

int main(){
    int t, n, k, id, a, b, c;
    vector<pair<int,int>> vet;
    vector<int> ans;
    scanf("%d", &t);
    while(t--){
        cin >> n >> k;
        vet.clear();
        ans.clear();
        for(int i = 0; i < n ; ++i){
            scanf("%d%d%d%d", &id, &a, &b, &c);
            vet.push_back(make_pair(a*b*c,id));
        }
        sort(vet.begin(), vet.end(), cmp);
        for(int i = n-k; i < n ; ++i){
          ans.push_back(vet[i].second);
        } 
        sort(ans.begin(), ans.end());
        for(int i = 0; i < k ; ++i){
            if(i==k-1) printf("%d", ans[i]);
            else printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

//Solution DP TOP-DOWN - TLE
// #include <bits/stdc++.h>
// using namespace std;
// #define oo 0x3f3f3f3f

// typedef vector<pair<int,int>> vii;
// typedef vector<int> vi;
// vii v;
// vi ans;
// int n, k, t, el;
// map<pair<int,int>,int> memo;

// int dp(int ind, int p){
//     if(ind == n && p < k) return -oo;
//     if(p == k) return 0;
//     int& ans = memo[{ind,p}];
//     if(ans != 0) return ans;
//     return ans = max(dp(ind+1, p), v[ind].second + dp(ind+1, p+1));
// }

// void recover(int ind, int p){
//     if(p == k) return ;
//     int a = dp(ind+1, p);
//     int b = v[ind].second + dp(ind+1, p+1);
//     if(b > a) {
//         ans.push_back(v[ind].first);
//         return recover(ind+1, p+1);
//     }
//     recover(ind+1, p);
// }

// int main(){
//     cin >> t;
//     while(t--){
//         cin >> n >> k;
//         memo.clear();
//         v.assign(n,{0,0});
//         for(int i = 0; i < n ; ++i){
//             int id, a, b, c;
//             cin >> id >> a >> b >> c;
//             v[i] = make_pair(id, a*b*c);
//         }
//         dp(0,0);
//         ans.clear();
//         recover(0,0);
//         sort(ans.begin(), ans.end());
//         for(int i = 0; i < ans.size() ; ++i){
//             printf("%d", ans[i]);
//             if(i != ans.size()-1) printf(" ");
//         }
//         printf("\n");
//     }

//     return 0;
// }
