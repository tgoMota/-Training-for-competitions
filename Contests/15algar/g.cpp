#include <bits/stdc++.h>
using namespace std;

string intToBin(int a){
  string ans = "";
  while(a){
    ans += (a%2 == 0)? '0' : '1';
    a/=2;
  }
  //reverse(ans.begin(), ans.end());
  return ans;
}

bool isPalin(string& a){
  for(int i = 0, j = a.size()-1; i < j ; i++, j--){
    if(a[i] != a[j]) return false;
  }
  return true;
}

int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    int a, b;
    scanf("%d%d", &a, &b);
    double t1 = clock();
    int qtd = 0, sum = 0;
    for(int i = a; i <= b ; ++i){
      string numa = to_string(i);
      string numb = intToBin(i);
      if(isPalin(numa) && isPalin(numb)){
        qtd++;
        sum+=i;
      }
    }
    printf("%d %d\n", sum, qtd);
    double t2 = clock() - t1;
    //printf("Tempo de execucao: %.2lf s\n", t2/CLOCKS_PER_SEC);
  }
  return 0;
}