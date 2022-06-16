class Solution {
public:
  /*
  time complexity: O(n^2)
  space complexity: O(n)
  where n is size of the input string
  */
    string longestPalindrome(string s) {
        // initialize memo as an array of 2's
        vector<char> memo(s.size(),2);
        
        memo[s.size()-1] = 1;
        int mx_len = 1; // maximum palindromic substring length
        int mx_l = s.size()-1; // maximum palindromic substring starting index
        
        // for all substrings, check whether they are palindrome or not
        // if palindrome, update answer if necessary
        for(int l = (int)s.size()-2;l > -1;l--)
        {
            for(int r = s.size()-1;r >= l;r--)
            {
              // consider substring starting at index l, ending at index r (l,r inclusive)
              // check whether the substring is palindrome or not by using previous computations
                bool isPal = false;
                if(l == r || (l == r-1 && s[l] == s[r]) || (l < r-1 && s[l] == s[r] && memo[r-1] == 1))
                {
                    isPal = true;
                    memo[r] = 1;
                }
                else
                    memo[r] = 0;
              // if palindrome, update answer if necessary
                if(isPal)
                {
                    int len = r-l+1;
                    if(len > mx_len)
                    {
                        mx_len = len;
                        mx_l = l;
                    }
                }
            }
        }
        return s.substr(mx_l,mx_len);
    }
};
