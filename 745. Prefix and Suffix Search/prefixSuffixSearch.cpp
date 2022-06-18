class WordFilter {
public:
    typedef struct Trie
    {
        typedef struct TrieNode
        {
            int idx;
            unordered_map<char,TrieNode*> children;
            TrieNode()
            {
                idx = -1;
            }
        }TrieNode;
        
        TrieNode* root;
        
        Trie()
        {
            root = new TrieNode();
        }
        
        void addToTrie(string &s, int wordIdx, TrieNode* node, int idx = 0)
        {
            if(idx == s.size())
            {
                node -> idx = wordIdx;
                return ;
            }
            unordered_map<char,TrieNode*> &ch = node-> children;
            if(ch[s[idx]] == nullptr)
            {
                ch[s[idx]] = new TrieNode();
            }
            addToTrie(s, wordIdx, ch[s[idx]], idx+1);
        }
        
        int dfs(TrieNode *node)
        {
            if(node == nullptr)
                return -1;
            int ans = node->idx;
            for(auto it : node->children)
            {
                int cnd = dfs(it.second);
                ans = max(ans,cnd);
            }
            return ans;
        }
        
        int findInTrie(string &s)
        {
            TrieNode *node = root;
            for(int idx = 0;idx < s.size();idx++)
            {
                node = node->children[s[idx]];
                if(node == nullptr)
                    return -1;
            }
            return dfs(node);
        }
    }Trie;
    
    Trie *t;
    
    WordFilter(vector<string>& words) {
        t = new Trie();
        for(int j = 0; j<words.size(); j++)
        {
            string &word = words[j];
            for(int i = 0;i<=word.size();i++)
            {
                string s= word.substr(i) + "#" + word;
                t->addToTrie(s,j,t->root);
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string s=suffix + "#" + prefix;
        return t->findInTrie(s);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
