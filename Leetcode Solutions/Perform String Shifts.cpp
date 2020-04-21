class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shi) {
        int sum = 0;
        const int N = shi.size(), M = s.size();
        for(int i = 0; i < N ; ++i){
            if(shi[i][0] == 0) sum+=shi[i][1];
            else sum-=shi[i][1];
        }
        
        
        int cpy = abs(sum);
        if(cpy == M || cpy%M == 0) sum = 0;
        else if(cpy > M) cpy -= ((cpy/M) * M);

        if(sum == 0) return s;
        else if(sum < 0) return s.substr(M-cpy,M)+ s.substr(0,M-cpy);
        else return s.substr(cpy,M-cpy) + s.substr(0,cpy);
    }
};