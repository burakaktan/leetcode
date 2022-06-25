class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int climbStairs(int n) {
        if(n < 2)
            return 1;
        int prev = 1;
        int curr = 1;
        for(int i = 2;i <= n;i++)
        {
            curr += prev;
            prev = curr - prev;
        }
        return curr;
    }
};
