/*
Time Complexity: O(N + A^2)
Space Complexity: O(A)
where N is size of the input and A is the alphabet size (26 for this question)

*/
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(char ch : s)
            m[ch]++;
        unordered_set<int> cnt;
        int ans = 0;
        for(auto element : m)
        {
            int it = element.second;
            if(cnt.find(it) == cnt.end())
            {
                cnt.insert(it);
            }
            else if(it == 1)
            {
                ans++;
            }
            else
            {
                do
                {
                    it--;
                    ans++;
                }
                while(cnt.find(it) != cnt.end());
                if(it != 0)
                    cnt.insert(it);
                    
            }
        }
        return ans;
        
    }
};
