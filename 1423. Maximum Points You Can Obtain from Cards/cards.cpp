class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    where n is number of cards
    Main idea:
        Two pointer
    */
    int maxScore(vector<int>& cardPoints, int k) {
        int r = cardPoints.size()-k;
        int sum = 0;
        
        for(int i = r;i<cardPoints.size();i++)
            sum += cardPoints[i];
        
        int mxScore = sum;
        
        for(int l = 0;l < k;l++,r++)
        {
            sum += cardPoints[l];
            sum -= cardPoints[r];
            mxScore = max(sum,mxScore);
        }
        
        return mxScore;
    }
};
