class Solution {
public:
    /*
    Time Complexity: O(n) where n is size of b
    Space Complexity: O(1)
    */
    const int mod = 1337;
    int modulo_pow(int base,int ex)
    {
        int ans = 1;
        while(ex--)
        {
            ans *= base;
            ans %= mod;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        a %= mod;
        int ans = 1;
        for(auto it : b)
        {
            ans = modulo_pow(ans,10);
            ans *= modulo_pow(a,it);
            ans %= mod;
        }
        return ans;
    }
};
