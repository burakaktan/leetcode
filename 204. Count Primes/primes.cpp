class Solution {
public:
    /*
    algo 1: for all numbers from 0 to n, check whether they are prime or not
        Time Complexity: O(n*sqrt(n))
        Space Complexity: O(1)
    algo 2: sieve of eratothenes
        Time Complexity: O(n)
        Space Complexity: O(n)
    */
    int countPrimes(int n) {
        int lim = sqrt(n);
        vector<bool> prime(n+1,true);
        for(int i = 2;i<=lim;i++)
        {
            if(!prime[i])
                continue;
            for(int j = i+i;j<n;j+=i)
            {
                prime[j] = false;
            }
        }
        int ans = 0;
        for(int i = 2;i<n;i++)
            if(prime[i])
                ans++;
        return ans;
    }
};
