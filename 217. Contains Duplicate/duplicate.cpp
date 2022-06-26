class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    where n is size of the input array
    
    Main idea:
    Let's have a hash set
    Iterate through the input and add each element into the hash set
    If the element is in the hash set before adding in this iteration, it means we previously saw  this number
    */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums)
        {
            // if num is present in the hash set, it means we previously saw  this number
            if(s.find(num) != s.end())
                return true;
            s.insert(num);
        }
        return false;
    }
};
