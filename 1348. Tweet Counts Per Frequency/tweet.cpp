/*
Time Complexity: O(QlogN)
Space Complexity: O(N)
where Q is number of queries and N is number of tweets
*/
class TweetCounts {
public:
    unordered_map< string,multiset<int> > tweets;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].insert(time);
        
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int fr;
        if(freq == "minute")
        {
            fr = 60;
        }
        else if(freq == "hour")
        {
            fr = 3600;
        }
        else
            fr = 86400;
        vector<int> ans;
        int l = startTime;
        while(l <= endTime)
        {
            int r = l + fr - 1;
            if(r > endTime)
                r = endTime;
            ans.push_back(search(tweetName,l,r));
            l = r+1;
        }
        return ans;
        
    }
private:
    int search(const string &tweetName,int start,int end)
    {
        multiset<int>::iterator l = tweets[tweetName].lower_bound(start);
        multiset<int>::iterator r = tweets[tweetName].upper_bound(end);
        if(l == tweets[tweetName].end())
            return 0;
        int ans = 0;
        while(l != r)
        {
            l++;
            ans++;
        }
        return ans;
    }
};
// the comment below is given by LeetCode
/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
