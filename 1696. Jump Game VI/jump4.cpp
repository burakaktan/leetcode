class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(k)
    
    Main idea:
    
    answer  is f(0)
    where
    f(i) = nums[i] + max(f(i+1),f(i+2), ... f(i+k))
    
    use monotonic stack to find max(f(i+1),f(i+2), ... f(i+k))
    */
    // 
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return nums.back();
        deque<pair<int,int> > f; // i,f(i) pairs
        f.push_back(make_pair(n-1,nums.back()));
        int fi;
        for(int i = n-2;i >= 0;i--)
        {
            fi = nums[i] + f.front().second;
            while(!f.empty() && f.front().first - i >= k)
                f.pop_front();
            while(!f.empty() && f.back().second <= fi)
                f.pop_back();
            f.push_back(make_pair(i,fi));
        }
        return fi;
    }
};
