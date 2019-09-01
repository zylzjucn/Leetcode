class SnakeGame {
    
    int row;
    int col;
    vector<vector<int>> m;
    queue<pair<int, int>> f;
    unordered_map<string, pair<int, int>> um;
    deque<pair<int, int>> d;
    int score = 0;
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        row = height;
        col = width;
        vector<int> v(col, 0);
        for (int i = 0; i < row; i++)
            m.push_back(v);
        m[0][0] = 1;
        d.emplace_back(0, 0);
        for (const auto& p : food)
            f.emplace(p[0], p[1]);
        um["U"] = make_pair(-1, 0);
        um["D"] = make_pair(1, 0);
        um["L"] = make_pair(0, -1);
        um["R"] = make_pair(0, 1);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int i = d.front().first + um[direction].first;
        int j = d.front().second + um[direction].second;
        if (i < 0 || i >= row || j < 0 || j >= col)
            return -1;
        if (i == f.front().first && j == f.front().second) {
            m[i][j] = 1;
            d.emplace_front(i, j);
            f.pop();
            return ++score;
        }
        m[d.back().first][d.back().second] = 0;
        d.pop_back();
        if (m[i][j] == 1)
            return -1;
        m[i][j] = 1;
        d.emplace_front(i, j);
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
