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
class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(h)
    where n is number of nodes and h is depth of the tree
    */
    unordered_map<int,int> m_inorder;
    TreeNode* solve(vector<int> &pre,vector<int> &in, int pl,int pr,int il,int ir)
    {
        if(pr < pl)
            return nullptr;
        int root_idx = m_inorder[pre[pl]];
        int left_subtree_size = root_idx - il;
        int right_subtree_size = ir - root_idx;
        TreeNode *left = solve(pre,in,pl+1,pl+left_subtree_size,il,root_idx-1);
        TreeNode *right =  solve(pre,in,pr-right_subtree_size+1,pr,root_idx+1,ir);
        return new TreeNode(pre[pl],left,right);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++)
        {
            m_inorder[inorder[i]] = i;
        }
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
