class Solution {
public:
/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is size of the input

Main idea:
Add all input numbers into a hash set.
iterate thruogh the input, if current_number-1" is not in the input(checked by hash set), this number is beginning of a consecutive interval.
Discover sizes of all consecutive intervals, return size of longest one

*/
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(int num : nums)
        {
            m.insert(num);
        }
        
        int ans = 0;
        for(int num: nums)
        {
            // can't be beginning of a sequence
            if(m.find(num-1) != m.end())
                continue;
            int cnt = 1;
            while(m.find(num+1) != m.end())
            {
                num++;
                cnt++;
            }
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};
