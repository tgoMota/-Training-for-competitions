//http://www.codcad.com/problem/53
//Soma de Casas
#include <bits/stdc++.h>
using namespace std;
int n, casas[100001], k;
int main(){
    cin >> n;
    for(int i = 0; i < n ; ++i) cin >> casas[i];
    cin >> k;
    for(int i = 0; i < n ; ++i){
        int sum = k - casas[i];
        if(binary_search(casas, casas+n, sum)) {
            cout << casas[i] << " " << sum << endl;
            break;
        }
    }
	return 0;
}