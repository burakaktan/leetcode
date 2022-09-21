class Solution {
public:
    /*
    time complexity: O(n+q)
    space complexity: O(1)
    */
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even_sum = 0;
        for(auto it:nums)
            if(it % 2 == 0)
                even_sum += it;
        vector<int> ans;
        ans.reserve(queries.size());
        for(auto q: queries)
        {
            if(nums[q[1]] % 2 == 0)
                even_sum -= nums[q[1]];
            nums[q[1]] += q[0];
            if(nums[q[1]] % 2 == 0)
                even_sum += nums[q[1]];
            ans.push_back(even_sum);
        }
        return ans;
    }
};
