// https://www.urionlinejudge.com.br/judge/pt/problems/view/2700
// URI 2700 - Angariando Fundos
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
struct p {
  int a, b, c;
  p(int a, int b, int c) : a(a), b(b), c(c) {}
};

int dp(int ind, vector<int> all){
    
}

int main() {

    int n, a, b, c, sum = 0;
    vector<p> vet;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        vet.push_back({a,b,c});
    }
    for (int i = 0; i < vet.size(); ++i) {
        for (int j = 0; j < vet.size(); ++j) {
            if(i == j || (vet[j].a == vet[j].b && vet[i].a == vet[i].b)) continue;
            if((vet[i].a >= vet[j].a && vet[i].b >= vet[j].b) || (vet[i].a <= vet[j].a && vet[i].b <= vet[j].b)) continue;
            if(vet[i].c > vet[j].c){
                printf("Apagando: %d %d %d\n", vet[j].a , vet[j].b, vet[j].c);
                vet.erase(vet.begin()+j, vet.begin()+j+1);
            }
            else{
                printf("Apagando: %d %d %d\n", vet[i].a , vet[i].b, vet[i].c);
                vet.erase(vet.begin()+i, vet.begin()+i+1);
            }
            if(i > 0) i--;
            if(j > 0) j--;
        }
    }

    for (p x : vet) {
        //printf("%d ", x.c);
        sum += x.c;
    }
    printf("%d\n", sum);

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// struct p {
//   int a, b, c;
//   p(int a, int b, int c) : a(a), b(b), c(c) {}
// };

// int main() {

//     int n, a, b, c, sum = 0;
//     vector<p> vet;
//     scanf("%d", &n);
//     for (int i = 0; i < n; ++i) {
//         scanf("%d%d%d", &a, &b, &c);
//         vet.push_back({a,b,c});
//     }
//     for (int i = 0; i < vet.size(); ++i) {
//         for (int j = 0; j < vet.size(); ++j) {
//             if(i == j || (vet[j].a == vet[j].b && vet[i].a == vet[i].b)) continue;
//             if((vet[i].a >= vet[j].a && vet[i].b >= vet[j].b) || (vet[i].a <= vet[j].a && vet[i].b <= vet[j].b)) continue;
//             if(vet[i].c > vet[j].c){
//                 printf("Apagando: %d %d %d\n", vet[j].a , vet[j].b, vet[j].c);
//                 vet.erase(vet.begin()+j, vet.begin()+j+1);
//             }
//             else{
//                 printf("Apagando: %d %d %d\n", vet[i].a , vet[i].b, vet[i].c);
//                 vet.erase(vet.begin()+i, vet.begin()+i+1);
//             }
//             if(i > 0) i--;
//             if(j > 0) j--;
//         }
//     }

//     for (p x : vet) {
//         //printf("%d ", x.c);
//         sum += x.c;
//     }
//     printf("%d\n", sum);

//     return 0;
// }