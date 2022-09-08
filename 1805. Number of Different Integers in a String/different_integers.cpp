class Solution {
public:
  /*
  Time Complexity: O(n)
  Space Complexity: O(n)
  where n is size of the input
  */
    inline bool isDigit(char ch){return ch <= '9' && ch >= '0';}
    void clearLeadingZeros(string &s)
    {
        reverse(s.begin(),s.end());
        while(s.size() > 1 && s.back() == '0')
            s.pop_back();
        reverse(s.begin(),s.end());
    }
    void addStringToHashSet(string &s,unordered_set<string> &hs)
    {
        clearLeadingZeros(s);
        hs.insert(s);
        s="";
    }
    int numDifferentIntegers(string word) {
        unordered_set<string> hs;
        string num = "";
        for(int i = 0;i<word.size();i++)
        {
            char current = word[i];
            char prev = (i==0)?'\0':word[i-1];
            if(isDigit(current))
            {
                num += current;
            }
            else if(isDigit(prev))
            {
               addStringToHashSet(num,hs);
            }
        }
        if(num != "")
            addStringToHashSet(num,hs);
        return (int)hs.size();
    }
};
