class Solution {
public:
    /*
    logic:
    sort the input, 
    iterate through the input:
        get prefix sum (by using previous value of it)
        when we choose current element, to make everything equal to it:
        number of increments: (current_index)*(curent_element) - prefix sum
        number of decrements = (total_sum - prefix_sum) - (n-current_index - 1)*(curent_element)
    choose minimum(increments+decrements)
    
    Time Complexity: O(nlogn)  , bottleneck is sorting
    Space Complexity: O(1) 
    */
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prefix_sum = 0;
        int n = nums.size();
        
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        long ans = 1ll*INT_MAX;
        for(int i = 0;i<nums.size();i++)
        {
            int curr = nums[i];
            prefix_sum += curr;
            long increments = 1ll*(i+1)*curr - 1ll*prefix_sum;
            long decrements = 1ll*(sum - prefix_sum) - 1ll*(n-i-1)*curr;
            ans = min(ans, increments+decrements);
        }
        return (int)ans;
    }
};
