class Solution {
public:
    /*
    Time Complexity: O(N)
    Space Complexity: O(N)
    Main idea:
    construct an answer like {1,-1,2,-2,3,-3,4,-4.....}
    if n is odd, the last element can be zero.
    */
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);
        for(int i = 0;i<n/2;i++)
        {
            ans[i+i] = (i+1);
            ans[i+i+1] = -(i+1);
        }
        return ans;
    }
};
