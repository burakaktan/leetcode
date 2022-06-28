class Solution {
public:
    /*
    Time Complexity: O(logn)
    Space complexity: O(1)
    
    Main idea:
    Count number of 5 factors (divide n by 5 till n be equal to zero, sum up the quotients)
    */
    int trailingZeroes(int n) {
        int quotient_sum = 0;
        while(n > 0)
        {
            quotient_sum += (n/=5);
        }
        return quotient_sum;
    }
};
