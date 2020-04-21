//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
//762. Prime Number of Set Bits in Binary Representation
class Solution {
public:
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    bool isPrime(int x){
        for(int i = 0; i < primes.size() ; ++i) if(x == primes[i]) return true;
        return false;
    }
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i = L; i <= R ; ++i) if(isPrime(__builtin_popcount(i))) ans++;
        return ans;
    }
};