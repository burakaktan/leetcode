class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n < 3)
            return 1;
        int curr = 1;
        int prev = 1;
        for(int i = 3;i<=n;i++)
        {
            int back_up = curr;
            curr += prev;
            prev = back_up;
        }
        return curr;
    }
};
