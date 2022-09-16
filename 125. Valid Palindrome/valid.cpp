class Solution {
public:
  /*
  main idea: two pointers
  Time Complexity: O(n)
  Space Complexity: O(1)
  */
    bool isAlpha(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    void increment_pointer(int &p,const string &s)
    {
        do
            p++;
        while(p < s.size() && !isAlpha(s[p] ));
    }
    void decrement_pointer(int &p,const string &s)
    {
        do
            p--;
        while(p >= 0 && !isAlpha(s[p]));
    }
    bool check(char ch1,char ch2)
    {
        if((ch1 <= '9' && ch1 >= '0') || (ch2 <= '9' && ch2 >= '0'))
            return ch1 == ch2;
        return ch1 == ch2 || (int)ch1 + ('a'-'A') == (int)ch2 || (int)ch1 - ('a'-'A') == (int)ch2;
    }
    bool isPalindrome(string s) {
        int l = 0,r = s.size()-1;
        if(!isAlpha(s[0]))
            increment_pointer(l,s);
        if(!isAlpha(s.back()))
            decrement_pointer(r,s);
        while(l < r)
        {
            if(!check(s[l],s[r]))
                return false;
            increment_pointer(l,s);
            decrement_pointer(r,s);
        }
        return true;
    }
};
