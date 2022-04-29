class Twitter {
public:
    
    map<int, vector<pair<int, int>>>tweet; //storing userId as key and and all tweets in vector as values;
    map<int, set<int>>graph;
    int count = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        // if(!tweet.count(userId))
        //     tweet[userId] = vector<int>();
        tweet[userId].push_back({tweetId, count++});
        
    }
    
    vector<int> getNewsFeed(int userId) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        // cout<<userId;
        vector<pair<int, int>>tweets = tweet[userId];
        for(auto it : tweets)
        {
            // cout<<it.first<<" ";
            pq.push({it.second,it.first});
            if(pq.size() > 10)
                pq.pop();
        }
        // for(auto it : graph[userId]) {
            set<int>st = graph[userId];
            for(auto it2 : st) {
                vector<pair<int, int>>vt = tweet[it2];
                for(auto k : vt) {
                    cout<<k.second<<" ";
                    pq.push({k.second,k.first});
                    if(pq.size() > 10)
                        pq.pop();
                }
            }
        // }
        vector<int>recentTweets;
        while(!pq.empty()) {
            pair<int, int>tp = pq.top();
            pq.pop();
            recentTweets.push_back(tp.second);
        }
        reverse(recentTweets.begin(), recentTweets.end());
    
        return recentTweets;
        
    }
    
    void follow(int followerId, int followeeId) {
        
        graph[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
        auto it = graph[followerId].find(followeeId);
        if(it != graph[followerId].end())
        graph[followerId].erase(it);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */