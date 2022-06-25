class Solution {
public:
    /*
    Time complexity: O(N)
    Space complexity: O(1)
    */
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <= 2)
            return true;
        int prev = INT_MIN;
        bool modified = false;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] <= nums[i+1])
            {
                prev = nums[i];
                continue;
            }
            if(modified)
                return false;
            modified = true;
            // two candidate solutions
            // 1) nums[i] = prev
            // 2) nums[i+1] = nums[i]
            if(prev <= nums[i+1])
                nums[i] = prev;
            else
                nums[i+1] = nums[i];
        }
        return true;
    }
};
