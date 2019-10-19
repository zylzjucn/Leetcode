class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return validinOrder(p1, p2, p3, p4) || validinOrder(p1, p2, p4, p3) || validinOrder(p1, p3, p2, p4) || validinOrder(p1, p3, p4, p2) || validinOrder(p1, p4, p2, p3) || validinOrder(p1, p4, p3, p2);
    }
    
    bool validinOrder(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12 = distanceSquare(p1, p2);
        int d23 = distanceSquare(p2, p3);
        int d34 = distanceSquare(p3, p4);
        int d41 = distanceSquare(p4, p1);
        int d13 = distanceSquare(p1, p3);
        int d24 = distanceSquare(p2, p4);
        if (d12 == d23 && d23 == d34 && d34 == d41 && d13 == d24 && d13 == 2 * d12 && d12 != 0)
            return true;
        return false;
    }
    
    int distanceSquare(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
