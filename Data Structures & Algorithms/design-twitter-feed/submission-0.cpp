class Twitter {
private:
    int time;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>follows;
public:
    Twitter() {
        time=0;
       
    }
    
    void postTweet(int userId, int tweetId) {
        time+=1;
        tweets[userId].push_back({time,tweetId});
        follows[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>maxHeap;
        
       for(int followeeId:follows[userId]){
          if(tweets.find(followeeId)!=tweets.end()){
            for(auto&tweet:tweets[followeeId]){
                maxHeap.push(tweet);
               
            }
          }
       }
       vector<int>res;
       while(!maxHeap.empty()&&res.size()<10){
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
       }
       return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId && follows.find(followerId)!=follows.end()){
            follows[followerId].erase(followeeId);
        }
    }
};
