class Solution {
public:
    /*
    Time Complexity: O(NlogK)
    Space Complexity: O(K)
    */
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int num : nums)
        {
            if(pq.size() < k)
            {
                pq.push(num);
                continue;
            }
            if(pq.top() >= num)
                continue;
            if(pq.top() < num)
                pq.pop();
            pq.push(num);
            
        }
        return pq.top();
    }
};
