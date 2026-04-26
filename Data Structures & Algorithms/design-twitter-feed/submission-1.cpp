class Twitter {
    unordered_map<int, unordered_set<int>> userFolloweeMap;
    unordered_map<int, vector<pair<int, int>>> userTweetsMap;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweetsMap[userId].push_back(make_pair(time++, tweetId));
        userFolloweeMap[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> heapOfTweets;
        auto followees = userFolloweeMap[userId];

        for(auto& followee: followees) {
            auto tweetsByFollowee = userTweetsMap[followee];
            for(auto& tweet: tweetsByFollowee) {
                heapOfTweets.push(tweet);
            }
        }

        vector<int> res;
        while(res.size() < 10 && !heapOfTweets.empty()) {
            res.push_back(heapOfTweets.top().second);
            heapOfTweets.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userFolloweeMap[followerId].insert(followeeId);
        // for(auto& p: userFolloweeMap) {
        //     cout << p.first << ": ";
        //     for(auto& e: p.second) {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
        userFolloweeMap[followerId].erase(followeeId);
    }
};
