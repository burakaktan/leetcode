class Solution {
public:
    /*
    Time Complexity: O(log(Unsigned Int Max)) // may be thought as O(1)
    Space Complexity: O(1)
    */
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(uint32_t i = 0;i<32;i++)
        {
            if(n & (1u<<i))
                ans++;
        }
        return ans;
    }
};
