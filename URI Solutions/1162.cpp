#include <bits/stdc++.h>
using namespace std;
int n, a, trem[52], swaps, aux;

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        swaps = 0;
        for(int i = 1; i <= a ; ++i) cin >> trem[i];
        bool trocou = true;
        while(trocou){
            trocou = false;
            for(int j = 1; j < a ; ++j){
                if(trem[j] > trem[j+1]){
                    trocou = true;
                    aux = trem[j];
                    trem[j] = trem[j+1];
                    trem[j+1] = aux;
                    swaps++;
                }
            }
            a--;
        }
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }

    return 0;
}