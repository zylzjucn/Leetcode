class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(1,1);
        for(int i = 0; i < rowIndex; i++)
        {
            v.push_back(1);
            for(int j = i; j > 0; j--)
                v[j] += v[j - 1];
        }
        return v;
    }
};
