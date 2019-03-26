class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        vector<int> v;
        v.push_back(userId);
        v.push_back(tweetId);
        posts.push_back(v);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        const int limit = 10;
        int count = 0;
        vector<int> res;
        for (int i = posts.size() - 1; i >= 0 && count < limit; i--) {
            if (posts[i][0] == userId || (followings.find(userId) != followings.end() && followings[userId].find(posts[i][0]) != followings[userId].end())) {
                res.push_back(posts[i][1]);
                count++;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followings.find(followerId) == followings.end()) {
            unordered_set<int> s;
            s.insert(followeeId);
            followings[followerId] = s;
        }
        else
            followings[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }

private:
    unordered_map<int, unordered_set<int>> followings;
    vector<vector<int>> posts;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
