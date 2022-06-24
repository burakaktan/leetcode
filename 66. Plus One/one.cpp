class Solution {
public:
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)  // instead of constructing a new vector, I modified the input vector
    where N is size of the input array
    */
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        
        for(int i = (int)digits.size()-1;carry && i > -1;i--)
        {
            digits[i] ++;
            carry = (digits[i] == 10);
            if(carry)
                digits[i] = 0;
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
