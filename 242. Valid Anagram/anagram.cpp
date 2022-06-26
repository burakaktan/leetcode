class Solution {
public:
    /*
    Time complexity: O(n)
    Space Complexity: O(m)
    where n is total number of characters in s and t
    AND m is size of the alphabet(26)
    
    */
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(char ch : s)
            m[ch]++;
        for(char ch : t)
            m[ch]--;
        for(auto it : m)
            if(it.second != 0)
                return false;
        return true;
    }
};
