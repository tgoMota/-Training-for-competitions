class Solution {
public:
    int isValid(int a, int b, int c){
        if(a+b<=c || a+c<=b || b+c <= a) return false;
        return true;
    }
    int largestPerimeter(vector<int>& A) {
        if((int)A.size() < 3) return 0;
        sort(A.begin(), A.end(), greater<int>());
        for(int i = 0; i < A.size()-2 ; ++i){
            if(isValid(A[i], A[i+1], A[i+2])) return A[i]+A[i+1]+A[i+2];
        }
        return 0;
    }
};