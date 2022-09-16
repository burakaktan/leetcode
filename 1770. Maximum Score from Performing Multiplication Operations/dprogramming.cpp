class Solution {
public:
    /*
    algorithm: we'll have a 2-dimensional dp array
    first dimension -> how many elements from left are chosen
    second dimension -> how many elements from back are chosen
    
    f(i,j) = max(f(i+1,j) + multipliers[i+j]*arr[i], f(i,j+1) + multipliers[i+j]*arr[n-(1+i+j)])
    
    Time Complexity: O(m^2)
    Space Complexity: O(m^2)
    where m is size of multipliers array
    
    */
    
    int f(int i,int j,const vector<int>& nums, const vector<int>& mult,const int m,
          vector< vector<int> >&dp)
    {
        if(i+j == m)
            return 0;
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        dp[i][j] = 
            max(
            f(i+1,j,nums,mult,m,dp) +  mult[i+j]*nums[i],
             f(i,j+1,nums,mult,m,dp) + mult[i+j]*nums[nums.size()-(1+j)]
        );
        return dp[i][j];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector< vector<int> >dp(multipliers.size(), vector<int> (multipliers.size(),INT_MIN));
        return f(0,0,nums,multipliers,(int)multipliers.size(),dp);
    }
};
