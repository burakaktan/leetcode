// the comment below is given by Leetcode
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
    Time Complexity: O(N)
    Space Complexity: O(H)
    where N is the number of nodes in the tree, H is depth of the tree
    Main idea:
    Perform DFS, store maximum value till that node is discovered, compare max value and node's value
    */
    int goodNodes(TreeNode* root,int mxTillHere = INT_MIN)
    {
        if(root == nullptr)
            return 0;
        mxTillHere = max(root->val,mxTillHere);
        int ans = (root->val == mxTillHere)?1:0;
        ans += goodNodes(root->left,mxTillHere);
        ans += goodNodes(root->right,mxTillHere);
        return ans;
    }
};
