class Solution {
public:
    /*
    Time Complexity: O((2^N)*N*M) // Note: N is 16, M is 26 at maximum
    Space Complexity: O(1)
    */
    int maxLength(vector<string>& arr) {
        int limit = 1<<((int)arr.size());
             
        int ans = 0;
        for(int i = 1;i<limit;i++)
        {
            int characters = 0;
            bool problematic = false;
            for(int j = 0;j<arr.size();j++)
            {
                bool here = i & (1<<j);
                if(!here)
                    continue;
                for(char ch : arr[j])
                {
                    if(characters & (1<<(ch-'a')))
                    {
                        characters = 0;
                        problematic = true;
                        break;
                    }    
                    characters |= (1<<(ch - 'a'));
                }
                if(problematic)
                    break;
            }
            ans = max(ans,__builtin_popcount(characters));
        }
        return ans;
    }
};
