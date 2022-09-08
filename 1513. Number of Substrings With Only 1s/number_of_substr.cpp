class Solution {
public:
    /*
    let's interpret the input as a gruop of (number_of_consequent_occurrence,number) pairs 
    011110001 -> one 0, four 1, three 0, one 1
    answer is sum_of(n*(n+1)/2) % mod for all n before 1s
    instead of adding n*(n+1)/2 at the end of the batch, we can add them while we iterate through the batch, like:
    at first element of the batch increment ans by 1
    at second element of the batch increment ans by 2
    and so on...
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
