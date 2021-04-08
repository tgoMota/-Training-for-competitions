#include <bits/stdc++.h>
 
using namespace std;
 
int32_t main(){
 
    int quant,n,m,i;
    string palavra,linha,jap,bra;
 
    map<string,string>trad;
 
    cin >> quant;
    getchar();
 
 
    while(quant--){
 
         cin >> n >> m;
         getchar();
 
 
         for(i=0;i<n;i++){
 
            getline(cin,jap);
            getline(cin,bra);
 
            trad[jap] = bra;
 
         }
 
         for(i=0;i<m;i++){
 
            getline(cin,linha);
 
            stringstream ss(linha);
            int idx = 0;
            while(ss >> palavra){
 
                if(trad.count(palavra) == 0){
                    if(idx++) cout << " ";
                    cout << palavra;
                }
 
                else{
                    if(idx++) cout << " ";
                    cout << trad[palavra];
               }
            }
            cout << '\n';
         }
 
 
        cout << '\n';
        trad.clear();

    }
 
}