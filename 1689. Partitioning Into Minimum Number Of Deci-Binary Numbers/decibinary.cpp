class Solution {
public:
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    where N is number of characters in the input array
    */
    int minPartitions(string n) {
        return (int)(*max_element(n.begin(),n.end()) - '0');
    }
};
