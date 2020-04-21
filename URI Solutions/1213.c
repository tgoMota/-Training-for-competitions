#include <stdio.h>

int main()
{
//    long long int n, k; //SOLUCAO COM TIMELIMIT
//    int count;
//
//    while(scanf("%lli", &n) != EOF){
//        k = 1;
//
//        count = 1;
//        while(k % n != 0 && ++count){
//            k = (k * 10)+1;
//        }
//        printf("%d\n", count);
//    }
//
//    return 0;

    long long int n, k;
    int count;

    while(scanf("%lli", &n) != EOF){
        k = 1;

        count = 1;
        while(k % n != 0){
            k = ((10 * k)+1) % n;
            ++count;
        }
        printf("%d\n", count);
    }

    return 0;
}
