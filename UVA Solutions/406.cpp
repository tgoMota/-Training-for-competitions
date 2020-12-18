//https://onlinejudge.org/external/4/406.pdf
//UVA 406 - Prime Cuts
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sieve_size;
bitset<10000010> bs;
vector<int> primes;
void sieve(ll upTo){
    sieve_size = upTo+1;
    bs.set();
    bs[0] = bs[1] = 0;
    primes.clear();
    for(ll i = 2; i <= sieve_size ; ++i){
        if(bs[i] == 0) continue;
        for(ll j = i*i; j <= sieve_size ; j+=i){
            bs[j] = 0;
        }
        primes.push_back((int)i);
    }
}

bool isPrime(int num){
    if(num <= sieve_size) return bs[num];
    for(int i = 0; i < (int)primes.size() ; ++i){
        if(num % primes[i] == 0) return false;
    }
    return true;
}

int main(){
    int n, c;
    while(scanf("%d%d", &n, &c) != EOF){
        sieve(1010);
        printf("%d %d:", n, c);
        vector<int> all_primes = {1};
        for(int i = 2; i <= n ; ++i){
            if(isPrime(i)) all_primes.push_back(i);
        }
        int sz = (int)all_primes.size();
        int begin = 0, end = sz-1;
        int need = sz % 2 == 0 ? 2*c : 2*c-1;
        int cnt = 0;
        while(end-begin+1 > need){
            if(cnt%2 == 0) end--;
            else begin++;
            cnt++;
        }
        for(int i = begin; i <= end ; ++i) printf(" %d", all_primes[i]);
        printf("\n\n");
    }
    return 0;
}