#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

void quotientremainder(string num, ll m) {
   vector<int> vec;
   ll mod = 0;
   for (int i = 0; i < num.size(); i++) {
      int digit = num[i] - '0';
      mod = mod * 10 + digit;
      int quo = mod / m;
      vec.push_back(quo);
      mod = mod % m;
   }
   printf("%lld\n", mod);
}
int main(){
       string a;
       cin >> a;
       ll b;
       cin >> b;
       quotientremainder(a,b);
    return 0;
}