class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int count = 0;
        multiset<int> s;
        int sum = 0;
        for (int i = 0; i < h.size() - 1; i++) {
            int gap = h[i + 1] - h[i];
            if (gap <= 0)
                continue;
            if (count < ladders) {
                s.insert(gap);
                count++;
            }
            else {
                if (s.empty() || gap <= *s.begin())
                    sum += gap;
                else {
                    sum += *s.begin();
                    s.erase(s.begin());
                    s.insert(gap);
                }   
            }
            if (sum > bricks)
                return i;
        }
        return h.size() - 1;
    }
};
