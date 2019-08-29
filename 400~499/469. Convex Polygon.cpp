class Solution {
public:
    bool isConvex(vector<vector<int>>& p) {
        for (int i=0, pos=0, neg=0, n=p.size(); i < n; ++i) {
            long det = det2({p[i], p[(i+1)%n], p[(i+2)%n]});
        if ((pos|=(det>0))*(neg|=(det<0))) return false;
        }    
        return true;
    }
    // determinant of 2x2 matrix [A1-A0, A2-A0]
    long det2(const vector<vector<int>>& A) {
    	return (A[1][0]-A[0][0])*(A[2][1]-A[0][1]) - (A[1][1]-A[0][1])*(A[2][0]-A[0][0]);
    }
};
