/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = cost[0];
        int curr = cost[1];
        
        for(int i = 2;i < n;i++)
        {
            int backup = curr;
            curr = cost[i] + min(curr,prev);
            prev = backup;
        }
        return min(prev,curr);
    }
};
