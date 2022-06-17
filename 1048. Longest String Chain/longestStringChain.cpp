class Solution {
public:

    /*
    time complexity: O(N*L + NlogN)
    space complexity: O(N)
    
    where 
    N is length of the input vector
    L is the maximum length of a word
    */
    int longestStrChain(vector<string>& words) {  
        //sort the input according to length
        sort(words.begin(),words.end(),
             [](string &s1,string &s2){return s1.size() < s2.size();});
        unordered_map<string,int> p;
        // ans[i] --> length of the longest chain ending at index i
        vector<int> ans(words.size(),1);
        
        /*
          for each word w in input:
              generate all predecessors of w by removing one character from all positions
              for each predecessor:
                  if predecessor is in the input:
                    ans[i] = max(ans[i], ans[index of predecessor])
        */
        for(int j = 0;j<words.size();j++)
        {
            string &w = words[j];
            for(int i = 0;i < w.size();i++)
            {
                string pred;
                pred =  w.substr(0,i) + w.substr(i+1);
                if(p.find(pred) != p.end())
                {
                    ans[j] = max(ans[j],ans[p[pred]]+1);
                }
            }
            p[w] = j;
        }

        return *max_element(ans.begin(),ans.end());
    }
};
