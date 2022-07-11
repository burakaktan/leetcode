// The comment below is given by LeetCode
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Time Complexity: O(n)
Space Complexity: O(h)
where n is number of nodes and h is height of the tree
*/
class Solution {
public:
    void dfs(TreeNode *root, int level,vector<int> &v)
    {
        if(root == nullptr)
            return ;
        if((int)v.size() <= level)
            v.push_back(root->val);
        v[level] = root->val;
        dfs(root->left,level+1,v);
        dfs(root->right,level+1,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }
};
