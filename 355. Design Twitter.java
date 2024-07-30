class Twitter {

    HashMap<Integer, Integer> postedTweets;
    List<Integer> followers;
    List<Integer> followees;
    List<Integer> allTweets;

    public Twitter() {
        postedTweets = new HashMap<>();
        followers = new ArrayList<>();
        followees = new ArrayList<>();
        allTweets = new ArrayList<>();
    }

    public void postTweet(int userId, int tweetId) {
        postedTweets.put(tweetId, userId);
        allTweets.add(tweetId);
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new ArrayList<>();
        List<Integer> validFollowers = new ArrayList<>();
        for(int i = 0; i < followers.size(); i++) {
            if(followers.get(i) == userId)
                validFollowers.add(followees.get(i));
        }

        int count = 0;
        for(int i = allTweets.size() - 1; i >= 0; i--) {
            int tweetPoster = postedTweets.get(allTweets.get(i));
            if(tweetPoster == userId || validFollowers.contains(tweetPoster)) {
                if(count < 10) {
                    result.add(allTweets.get(i));
                    count++;
                }
            }
        }
        return result;
    }

    public void follow(int followerId, int followeeId) {
        followers.add(followerId); followees.add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        for(int i = 0; i < followers.size(); i++) {
            if(followers.get(i) == followerId && followees.get(i) == followeeId) {
                followers.remove(i);
                followees.remove(i);
            }
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */