class Vector2D {
public:
    Vector2D(vector<vector<int>>& m) {
        i = m.begin();
        end = m.end();
        j = 0;
    }
    
    int next() {
        hasNext();
        return (*i)[j++];
    }
    
    bool hasNext() {
        while (i != end && j == i->size())
            i++, j = 0;
        return i != end;
    }
private:
    vector<vector<int>>::iterator i;
    vector<vector<int>>::iterator end;
    int j;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
