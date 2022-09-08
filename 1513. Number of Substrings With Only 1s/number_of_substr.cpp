class Solution {
public:
    /*
    we'll interpret the input as a gruop of (number_of_consequent_occurrence,number) pairs 
    011110001 -> one 0, four 1, three 0, one 1
    answer is sum_of(n*(n+1)/2) % mod for all n before 1s
    Time Complexity: o(n)
    Space Complexity: O(1)
    where n is size of the input string
    */
    const int mod = 1e9+7;
    int numSub(string s) {
        int ans = 0;
        int occurrence = 0;
        char prev = s[0];
        for(char ch: s)
        {
            if(ch == prev)
                occurrence++;
            else
            {
                occurrence = 1;
                prev = ch;
            }
            if(ch == '1')
            {
                ans += occurrence;
                ans %= mod;
            }
        }
        return ans;
    }
};
