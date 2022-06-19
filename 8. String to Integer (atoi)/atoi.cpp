class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    where n is the length of input string
    */
    int myAtoi(string s) {
        int begin = 0;
        
        // ignore whitespace at the beginning
        while(begin < s.size() && s[begin] == ' ')
            begin++;
        
        // determine the sign
        bool sign = true;
        if(begin < s.size() && s[begin] == '-')
        {
            sign = false;
            begin++;
        }
        if(begin < s.size() && s[begin] == '+')
        {
            if(!sign)
                return 0;
            begin++;
        }
        
        // read till the end (or non-digit numbers start)
        int ans = 0;
        for(;begin < s.size() && s[begin] <= '9' && s[begin] >= '0';begin++)
        {
            // multiply by 10, check possible overflows
            if(ans > INT_MAX/10)
                return INT_MAX;
            if(ans < INT_MIN/10)
                return INT_MIN;
            ans *= 10;
            
            // add/substract the new digit, check possible overflows
            int toAdd = s[begin] - '0';
            if(sign)
            {
                if(ans > INT_MAX-toAdd)
                    return INT_MAX;
                ans += toAdd;
            }
            else
            {
                if(ans < INT_MIN+toAdd)
                    return INT_MIN;
                ans -= toAdd;
            }
        }
        
        return ans;
    }
};
