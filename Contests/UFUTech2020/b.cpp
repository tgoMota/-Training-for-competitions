#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

bool verify(string& w, int& x){
    const int N = (int)w.size();
    for(int i = 0; i < N ; ++i){
        if(isdigit(w[i])) return false;
        if(w[i] == '.' && i < N-1) return false;
        if(w[i] == '.') x++;
    }
    return true;
}

int main(){
    string s;
    while(getline(cin, s)){
        vector<string> v;
        string word = "";
        const int N = (int)s.size();
        int cmpAll = 0;
        for(int i = 0; i < N ; ++i){
            if((s[i] == ' ')){
                if(word.empty()) continue;
                int npoints = 0;
                if(verify(word, npoints)) {
                    v.push_back(word);
                    cmpAll+=(int)word.size()-npoints;
                }
                word = "";
            }else{
                word+=s[i];
                int npoints = 0;
                if(i == N-1 && verify(word, npoints)){
                    v.push_back(word);
                    cmpAll += (int)word.size()-npoints;
                }
            }
        }
        int numWords = (int)v.size();
        if(numWords == 0 || cmpAll/numWords <= 3) printf("250\n");
        else if(cmpAll/numWords <= 5) printf("500\n");
        else printf("1000\n");
    }
    return 0;
}

// #include <cstdio>
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <cctype>


// using namespace std;

// int main(int argc, char const *argv[])
// {
// 	int num, t, qtd, aux, cm,i;
// 	string frase;
// 	bool b;

// 	while(getline(cin,frase))
// 	{
// 		//t = frase.size();
// 		num = qtd = 0;
// 		string token;
// 		istringstream iss(frase);

// 		while ( getline(iss, token, ' ') )
// 		{
// 			b = true;
// 			t = token.size();
// 			aux = 0;

// 			for(i=0;i<t;i++)
// 			{
// 				if(isdigit(token[i]) || token[i] == '.' && i!=t-1 ){
// 					b = false;
// 					break;
// 				}else if(token[i] == '.'){
// 				}else aux++;
// 			}

// 			if(b){
// 				num += aux;
// 				qtd++;
// 			}
// 		}

// 		if(qtd == 0)  cm = 0 ;
// 		else cm = num/qtd;

// 		if(cm <=3) puts("250");
// 		else if(cm == 4 || cm == 5 ) puts("500");
// 		else puts("1000");
// 	}
// }