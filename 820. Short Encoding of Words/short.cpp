/*
    Time Complexity: O(total number of characters in the input)
    Space Complexity: O(total number of characters in the input)
    
    Main idea:
        Add reverse of input strings to a Trie
        answer is sum(depth+1) for all leaf nodes in the Trie
        (+1 is to count # signs)
*/
class Solution {
public:
    typedef struct Trie
    {
        typedef struct TrieNode
        {
            unordered_map<char,TrieNode*> children;
        }TrieNode;
        TrieNode *root;
        unordered_map<TrieNode*,int> nodes; // add <node,depth> pairs
        Trie()
        {
            root = new TrieNode();
            nodes[root] = 0;
        }
        void reverseAdd(const string &s)
        {
            TrieNode *curr = root;
            for(int i = s.size()-1;i > -1;i--)
            {   
                if(curr->children[s[i]] == nullptr)
                {
                    curr->children[s[i]] = new TrieNode();
                    nodes[curr->children[s[i]]] = s.size() - i;
                }
                
                curr = curr-> children[s[i]];
                
            }
        }
    }Trie;
    
    int minimumLengthEncoding(vector<string>& words) {
        Trie t;
        // add reverse of each input string to the Trie
        for(string &w : words)
        {
            t.reverseAdd(w);
        }
        
        int ans = 0;
        
        for(auto it : t.nodes)
        {
            // if node is a leaf node
            if(it.first->children.size() == 0)
                // increment answer by depth of that leaf node + 1
                ans += it.second + 1;
        }
        return ans;
    }
};
