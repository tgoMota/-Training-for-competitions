// //https://www.urionlinejudge.com.br/judge/pt/problems/view/1312
// //URI 1312 - Empilhamento de Bolas
// #include <bits/stdc++.h>
// using namespace std;

// int N, m[1001][1001];
// int sum[1001][1001], memo[1001][1001];

// int main(){
//     scanf("%d", &N);
//     for(int i = 1; i <= N ; ++i){
//         for(int j = 0; j < i ; ++j){
//             scanf("%d", &m[i][j]);
//         }
//     }

//     for(int i = 1; i <= N ; ++i){
//         for(int j = 0; j < i ; ++j){
//             sum[i][j] += sum[i-1][j] + (j? sum[i-1][j+1] : 0);
//         }
//     }


//     return 0;
// }