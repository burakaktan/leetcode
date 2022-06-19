class Solution {
public:
/*
main idea: sort the products alphabetically, then use two pointer method
*/
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int l = 0, r = products.size()-1;
        vector< vector<string> > ans;
        for(int i = 0;i<searchWord.size();i++)
        {
            char ch = searchWord[i];
            while(l < products.size() && (products[l].size() <= i || products[l][i] != ch))
                l++;
            while(r > -1 && (products[r].size() <= i || products[r][i] != ch))
                r--;
            vector<string> v;
            for(int i = l;i<l+3 && i <= r;i++)
            {
                v.push_back(products[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
