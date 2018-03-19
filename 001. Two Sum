class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) 
    {
        map<int, int> valuetoindex;
        vector<int> r;
        for(int i = 0; i < n.size(); i++) {
            if(valuetoindex.find(target - n[i]) != valuetoindex.end()) {
                r.push_back(valuetoindex[target - n[i]]);
                r.push_back(i);
                return r;
            }
            else
                valuetoindex[n[i]] = i;
        }
        return r;
    }
};
