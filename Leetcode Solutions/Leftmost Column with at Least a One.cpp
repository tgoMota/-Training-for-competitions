//Leftmost Column with at Least a One
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int bs(BinaryMatrix& matrix, int row, const int n){
        int lo = 0, hi = n-1;
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(matrix.get(row,mid) < 1) lo = mid+1;
            else hi = mid;
        }
        return matrix.get(row,lo) == 1 ? lo : n;
    }

    int leftMostColumnWithOne(BinaryMatrix &matrix) {
        vector<int> l = matrix.dimensions();
        int n = l[0], m = l[1];
        int mincolumn = m;
        for(int i = 0; i < n ; ++i){
            mincolumn = min(mincolumn,bs(matrix, i, m));
        }
        return mincolumn == m ? -1 : mincolumn;
    }
};