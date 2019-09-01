class MyCalendarTwo {
    
    vector<pair<int, int>> v;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (int i = 0; i < v.size(); i++) {
            if (max(v[i].first, start) < min(v[i].second, end))
                for (int j = i + 1; j < v.size(); j++)
                    if (max(v[j].first, max(v[i].first, start)) < min(v[j].second, min(v[i].second, end)))
                        return false;
        }
        v.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
