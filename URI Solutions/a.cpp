//URI Online Judge | 1259
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1259
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main(){
//     int t;
//     scanf("%d", &t);
//     for(int ti = 1; ti <= t ; ++ti){
//         int n;
//         scanf("%d", &n);
//         vector<int> v(n);
//         for(int i = 0; i < n ; ++i) scanf("%d", &v[i]);

//         sort(v.begin(), v.end());
//         vector<int> less(v.begin(), v.begin()+(int)v.size()/2);
//         vector<int> bigger(v.begin()+(int)v.size()/2, v.end());
//         reverse(bigger.begin(), bigger.end());
//         reverse(less.begin(), less.end());

//         vector<int> result;
//         int i = 0, j = 0;
//         while(i < (int)less.size() || j < (int)bigger.size()){
//             if(i < (int)less.size()) result.push_back(less[i]);
//             if(j < (int)bigger.size()) result.push_back(bigger[i]);
//             i++, j++;
//         }
        
//         ll sum = 0LL;
//         for(int i = 0; i < (int)result.size()-1 ; ++i){
//             sum += abs(result[i]-result[i+1]);
//         }
//         if(n == 1) sum += v[0];
//         printf("Case %d: %lld\n", ti, sum);
//         for(int x : result) printf("%d ", x);
//         printf("\n");
//     }
//     return 0;
// }
}