class Solution {
public:
    /*
    observation: smallest element is always original
                double of smallest is always added
    algorithm:
        have a tree set named t
        while t is not empty:
            erase smallest element (name it as s) and its double
            add s to original elements list
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    */
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = (int)changed.size()/2;
        if(n*2 != (int)changed.size())
            return {};
        vector<int> original;
        original.reserve(n);
        multiset<int> t;
        for(auto it: changed)
            t.insert(it);
        while(!t.empty())
        {
            int s = *t.begin();
            t.erase(t.begin());
            set<int>::iterator it = t.find(s<<1);
            if(it == t.end())
                return {};
            t.erase(it);
            original.push_back(s);
        }
        return original;
    }
};
