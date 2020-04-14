#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

long long findDigits(int n) 
{ 
    if (n < 0)  return 0; 
    if (n <= 1) return 1; 
  
    double x = ((n * log10(n / M_E) +  
                 log10(2 * M_PI * n) / 
                 2.0)); 
  
    return floor(x) + 1; 
} 

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){

    }
    return 0;
}